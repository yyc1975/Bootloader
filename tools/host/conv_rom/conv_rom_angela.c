
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



main(int argc, char *argv[])
{


  FILE *fluxin;
  FILE *fluxout;


//Inline Arg management
  int valid_option;
  int version;
  char *filename;



  int address, data;

  int sign, nextsign, j, bit_j, switch_print, data_tab_j_scrambled, add_expanded = 0;


  filename = malloc(500 * sizeof(char));



  // only one arg
  if ((argc > 2) || (argc<2) )
      {	      
	  printf("Usage: conv_rom <file>\n"); 
	  //exit(0); 
	  return(1);
      }

  strcpy(filename, argv[1]);
  printf("LONDA ROM converter V1.0\n");
   


  fluxin = fopen(filename, "r");

  if(fluxin == NULL)
    {
      printf("(conv_rom) Error, unable to open %s\n", filename);
      //exit(0);
      return(1);
    }
  else
    printf("(conv_rom) Info, Reading %s\n", filename);


  fluxout = fopen("ts3ga32768x32m32_c050228.hex", "w");

  if(fluxout == NULL)
    {
      printf("(conv_rom) Error, unable to write in ts3ga32768x32m32_c050228.hex\n");
      //exit(0);
      return(1);
    }
  else
    printf("(conv_rom) Info, Writing in ts3ga32768x32m32_c050228.hex\n");


  sign = 0;
  address = 0;

  for(address = 0; address < 16383; address++)  // MQ55 64kbyte
    {
      fscanf(fluxin, "%x", &data);
      //scrambling op
      data_tab_j_scrambled = 0;
      data_tab_j_scrambled = (unsigned int) (((data>>4)&1)*pow(2,31) +
				    ((data>>12)&1)*pow(2,30) +
				    ((data>>24)&1)*pow(2,29) +
				    ((data>>6)&1)*pow(2,28) +
				    ((data>>10)&1)*pow(2,27) +
				    ((data>>18)&1)*pow(2,26) +
				    ((data>>0)&1)*pow(2,25) +
				    ((data>>19)&1)*pow(2,24) +
				    ((data>>17)&1)*pow(2,23) +
				    ((data>>31)&1)*pow(2,22) +
				    ((data>>2)&1)*pow(2,21) +
				    ((data>>26)&1)*pow(2,20) +
				    ((data>>25)&1)*pow(2,19) +
				    ((data>>9)&1)*pow(2,18) +
				    ((data>>28)&1)*pow(2,17) +
				    ((data>>29)&1)*pow(2,16) +
				    ((data>>27)&1)*pow(2,15) +
				    ((data>>5)&1)*pow(2,14) +
				    ((data>>30)&1)*pow(2,13) +
				    ((data>>11)&1)*pow(2,12) +
				    ((data>>13)&1)*pow(2,11) +
				    ((data>>20)&1)*pow(2,10) +
				    ((data>>22)&1)*pow(2,9) +
				    ((data>>1)&1)*pow(2,8) +
				    ((data>>16)&1)*pow(2,7) +
				    ((data>>15)&1)*pow(2,6) +
				    ((data>>7)&1)*pow(2,5) +
				    ((data>>8)&1)*pow(2,4) +
				    ((data>>21)&1)*pow(2,3) +
				    ((data>>3)&1)*pow(2,2) +
				    ((data>>23)&1)*pow(2,1) +
				    ((data>>14)&1)*pow(2,0)); 

     
      data_tab_j_scrambled ^= 0xabbacaca;


      //add expension
      add_expanded = (unsigned int)(((address>>10)&1)*pow(2,31) + 
					  ((address>>2)&1)*pow(2,30) +
					  ((address>>6)&1)*pow(2,29) +
					  ((address>>12)&1)*pow(2,28) +
					  ((address>>4)&1)*pow(2,27) +
					  ((address>>11)&1)*pow(2,26) +
					  ((address>>12)&1)*pow(2,25) +
					  ((address>>3)&1)*pow(2,24) +
					  ((address>>4)&1)*pow(2,23) +
					  ((address>>7)&1)*pow(2,22) +
					  ((address>>8)&1)*pow(2,21) +
					  ((address>>13)&1)*pow(2,20) +
					  ((address>>3)&1)*pow(2,19) +
					  ((address>>7)&1)*pow(2,18) +
					  ((address>>9)&1)*pow(2,17) +
					  ((address>>10)&1)*pow(2,16) +
					  ((address>>5)&1)*pow(2,15) +
					  ((address>>13)&1)*pow(2,14) +
					  ((address>>8)&1)*pow(2,13) +
					  ((address>>5)&1)*pow(2,12) +
					  ((address>>4)&1)*pow(2,11) +
					  ((address>>9)&1)*pow(2,10) +
					  ((address>>11)&1)*pow(2,9) +
					  ((address>>13)&1)*pow(2,8) +
					  ((address>>2)&1)*pow(2,7) +
					  ((address>>8)&1)*pow(2,6) +
					  ((address>>3)&1)*pow(2,5) +
					  ((address>>2)&1)*pow(2,4) +
					  ((address>>6)&1)*pow(2,3) +
					  ((address>>10)&1)*pow(2,2) +
					  ((address>>5)&1)*pow(2,1) +
					  ((address>>8)&1)*pow(2,0));


      //xor with add expanded
      data_tab_j_scrambled ^= add_expanded;

      fprintf(fluxout, "%08x\n",data_tab_j_scrambled);


      //signature generation
      nextsign = data_tab_j_scrambled ^ ((sign & 0xffffffff) >> 1);
      nextsign ^= ((0x1 & sign) ^ ((0x4 & sign) >> 2) ^ (((1 << 26) & sign) >> 26) ^ (((1 << 29) & sign) >> 29)) << 31;
      sign = nextsign;

      // To workaround MQ55 A1 bug (Fisrt ROM byte is read twice)
      if(address == 0)
	  {
	      nextsign = data_tab_j_scrambled ^ ((sign & 0xffffffff) >> 1);
	      nextsign ^= ((0x1 & sign) ^ ((0x4 & sign) >> 2) ^ (((1 << 26) & sign) >> 26) ^ (((1 << 29) & sign) >> 29)) << 31;
	      sign = nextsign;
	  }

//      printf("scrambled data =  0x%08x\n",  data_tab_j_scrambled);
//      printf("sign = 0x%08x\n",sign);
    }


  fprintf(fluxout, "%08x\n", sign);

  fclose(fluxin);
  fclose(fluxout);

  printf("(conv_rom) Info, Ok\n");
  return(0);


}
