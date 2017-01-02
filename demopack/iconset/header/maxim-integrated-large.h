/*  GIMP header image file format (INDEXED): /home/alpha/Images/selectionslideshow/maxim-integrated-large.h  */

static unsigned int width = 225;
static unsigned int height = 65;

/*  Call this macro repeatedly.  After each use, the pixel data can be extracted  */

#define HEADER_PIXEL(data,pixel) {\
pixel[0] = header_data_cmap[(unsigned char)data[0]][0]; \
pixel[1] = header_data_cmap[(unsigned char)data[0]][1]; \
pixel[2] = header_data_cmap[(unsigned char)data[0]][2]; \
data ++; }

static char header_data_cmap[256][3] = {
	{ 58, 53, 52},
	{ 74, 75, 73},
	{ 43,181,164},
	{254,255,252},
	{ 62, 58, 57},
	{ 59, 54, 53},
	{ 68, 70, 67},
	{ 67, 62, 61},
	{ 76, 71, 70},
	{ 55,138,128},
	{ 49,171,156},
	{ 64, 60, 58},
	{ 50,146,134},
	{ 49,158,144},
	{ 71, 66, 65},
	{ 60,143,132},
	{ 53,180,158},
	{ 70, 95, 93},
	{ 47,156,143},
	{241,243,240},
	{ 80, 75, 74},
	{167,161,160},
	{106,101,100},
	{ 59, 55, 54},
	{ 74, 69, 68},
	{ 88, 83, 82},
	{120,115,114},
	{ 58, 60, 57},
	{ 75, 77, 74},
	{185,179,178},
	{248,250,246},
	{251,253,250},
	{ 57, 58, 56},
	{ 83, 78, 77},
	{182,176,175},
	{155,150,148},
	{217,219,215},
	{191,185,184},
	{134,129,127},
	{102, 97, 96},
	{203,206,202},
	{ 34,176,159},
	{ 73, 84, 85},
	{127,122,121},
	{ 95, 90, 89},
	{ 92, 87, 86},
	{ 86, 81, 80},
	{ 69, 64, 63},
	{ 45,168,153},
	{ 73, 68, 67},
	{ 96,199,184},
	{235,237,234},
	{230,225,223},
	{216,210,209},
	{ 99, 94, 93},
	{ 75, 70, 69},
	{235,229,228},
	{125,120,118},
	{250,244,243},
	{ 55, 84, 76},
	{ 52,118,104},
	{127,208,196},
	{ 77,193,178},
	{ 64,116,109},
	{ 94, 89, 88},
	{198,200,197},
	{ 62,113,107},
	{ 56,112, 99},
	{ 42,166,151},
	{159,154,153},
	{212,215,211},
	{155,218,209},
	{ 97, 92, 91},
	{ 57,151,139},
	{142,137,136},
	{148,143,141},
	{ 50,151,132},
	{ 71,188,173},
	{ 61,133,124},
	{ 55,101, 90},
	{ 57, 78, 71},
	{129,124,123},
	{178,173,172},
	{189,191,188},
	{174,168,167},
	{254,248,247},
	{ 58,146,129},
	{150,145,143},
	{139,134,133},
	{ 56, 64, 60},
	{ 45,129,119},
	{ 61,122,114},
	{194,196,193},
	{200,202,199},
	{249,252,248},
	{ 70, 88, 87},
	{ 59, 88, 80},
	{ 55,155,136},
	{111,106,105},
	{ 84, 79, 78},
	{ 39,164,149},
	{196,191,190},
	{238,240,237},
	{224,218,217},
	{172,166,165},
	{246,248,244},
	{ 54, 69, 63},
	{ 53,141,124},
	{ 56, 71, 65},
	{ 67,109,104},
	{114,110,108},
	{ 55, 92, 82},
	{ 58, 80, 73},
	{ 39,150,137},
	{170,164,163},
	{ 55, 57, 55},
	{ 50,122,113},
	{ 52,187,170},
	{ 65,107,102},
	{243,238,236},
	{ 72, 90, 89},
	{116,112,110},
	{230,232,229},
	{108,104,102},
	{ 60,172,151},
	{ 63,115,108},
	{ 56,169,148},
	{ 52,173,158},
	{243,245,242},
	{198,193,192},
	{239,234,232},
	{ 54, 76, 69},
	{ 64,125,117},
	{ 55,150,138},
	{ 77, 79, 76},
	{112,108,106},
	{210,205,203},
	{205,207,203},
	{ 51,178,156},
	{ 60,125,111},
	{ 54,120,106},
	{ 58, 73, 67},
	{ 67,101, 97},
	{221,223,220},
	{ 53,130,114},
	{ 96, 91, 90},
	{211,240,237},
	{ 69,103, 99},
	{ 48,144,132},
	{ 58,104, 93},
	{ 57,123,109},
	{ 54, 62, 58},
	{ 58, 66, 62},
	{170,224,216},
	{239,252,253},
	{220,214,213},
	{224,226,223},
	{ 51,165,145},
	{ 47,162,142},
	{ 53,109, 96},
	{ 56,133,117},
	{193,188,186},
	{247,241,240},
	{201,196,194},
	{205,199,198},
	{ 58,129,120},
	{181,183,180},
	{ 58, 95, 85},
	{116,207,194},
	{202,204,201},
	{109,114,116},
	{ 71, 82, 83},
	{122,117,116},
	{197,199,196},
	{131,126,125},
	{237,231,230},
	{143,215,204},
	{103, 99, 97},
	{ 75, 83, 79},
	{207,209,206},
	{ 41,138,127},
	{108,106,110},
	{196,233,229},
	{ 60, 97, 88},
	{ 68, 94, 91},
	{209,211,208},
	{228,230,227},
	{162,157,156},
	{113,111,115},
	{ 52,114,106},
	{ 73, 77, 79},
	{157,152,151},
	{136,131,130},
	{ 49,138,121},
	{ 97, 99, 96},
	{105,109,112},
	{ 48,120,111},
	{232,234,231},
	{ 52,160,147},
	{ 52,153,134},
	{102,104,101},
	{220,241,240},
	{ 59,159,140},
	{185,231,225},
	{ 59,114,102},
	{213,207,206},
	{225,247,246},
	{ 55,162,149},
	{103,101,105},
	{144,139,138},
	{ 45,174,152},
	{ 59,136,120},
	{111,202,189},
	{234,248,248},
	{ 60, 82, 75},
	{ 93,197,182},
	{187,182,181},
	{ 59,153,141},
	{ 51,102, 96},
	{106,108,105},
	{ 60, 62, 59},
	{232,245,246},
	{159,222,213},
	{ 56,107,101},
	{228,222,221},
	{ 59,184,162},
	{ 74, 78, 80},
	{ 66,117,111},
	{ 53,137,126},
	{165,160,158},
	{ 60, 53, 48},
	{ 91, 93, 90},
	{ 44,141,129},
	{236,246,241},
	{248,254,255},
	{255,255,255},
	{255,255,255},
	{255,255,255},
	{255,255,255},
	{255,255,255},
	{255,255,255},
	{255,255,255},
	{255,255,255},
	{255,255,255},
	{255,255,255},
	{255,255,255},
	{255,255,255},
	{255,255,255},
	{255,255,255},
	{255,255,255},
	{255,255,255},
	{255,255,255},
	{255,255,255},
	{255,255,255},
	{255,255,255},
	{255,255,255}
	};
static char header_data[] = {
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,152,79,196,90,86,13,10,
	2,16,126,18,107,139,67,111,32,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,131,189,97,16,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,41,193,79,151,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,27,196,100,2,2,2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,2,2,2,16,76,167,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,32,67,124,2,2,2,2,2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,2,2,2,2,2,2,199,59,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,46,26,5,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	79,68,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
	148,131,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,39,3,3,83,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,106,97,
	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
	2,16,116,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,35,3,3,128,5,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,59,10,2,
	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
	2,2,2,86,27,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,25,130,3,229,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,
	0,0,0,0,0,0,0,0,0,0,0,0,79,138,2,2,
	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
	2,2,2,2,13,108,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,5,8,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,
	0,0,0,0,0,0,0,0,0,0,0,116,2,2,2,2,
	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
	2,2,2,2,2,10,59,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,
	0,0,0,0,0,0,0,0,0,0,160,2,2,2,2,2,
	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,96,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,
	0,0,0,0,0,0,0,0,0,67,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,210,108,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,25,
	37,37,8,0,7,43,34,122,155,21,39,0,0,0,64,35,
	164,119,70,21,7,0,0,0,0,0,0,49,192,29,137,122,
	162,143,163,26,0,0,0,0,121,37,37,114,0,0,0,0,
	0,0,26,37,37,87,0,0,25,37,37,75,0,0,0,0,
	114,37,57,0,0,22,187,70,175,166,38,5,0,0,14,174,
	166,56,52,83,64,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,
	0,0,0,0,0,0,0,0,96,16,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,13,27,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,39,
	3,3,135,54,52,3,3,3,3,3,105,45,5,21,3,3,
	3,3,3,3,143,4,0,0,0,0,21,94,3,3,3,3,
	3,3,3,3,83,0,0,0,7,224,3,3,88,0,0,0,
	0,8,19,3,85,45,0,0,39,3,3,101,0,0,0,0,
	52,3,166,7,29,3,3,3,3,3,3,21,0,98,130,3,
	3,3,3,3,30,98,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,
	0,0,0,0,0,0,0,141,127,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,2,12,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,39,
	3,3,137,30,3,3,155,36,3,3,3,52,185,3,3,105,
	173,162,3,3,3,75,0,0,0,0,21,3,3,56,164,84,
	29,130,3,3,3,174,0,0,0,72,30,3,128,33,0,0,
	0,101,3,3,87,0,0,0,39,3,3,101,0,0,0,0,
	52,3,122,52,3,3,119,65,30,3,3,3,216,3,3,3,
	70,103,3,3,3,36,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,
	0,0,0,0,0,0,27,157,2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,2,2,139,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,39,
	3,3,3,3,34,33,0,0,135,3,3,3,3,19,81,7,
	0,7,29,3,3,83,0,0,0,0,172,21,64,0,0,0,
	0,0,187,3,3,161,0,0,0,0,35,3,3,93,5,0,
	174,3,3,137,5,0,0,0,39,3,3,101,0,0,0,0,
	52,3,3,3,186,98,5,0,8,155,3,3,3,3,82,20,
	0,0,121,3,3,3,47,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,
	0,0,0,0,0,0,150,2,2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,2,2,16,80,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,39,
	3,3,3,75,0,0,0,0,0,52,3,3,52,45,0,0,
	0,0,135,3,3,36,0,0,0,0,0,0,0,0,0,0,
	0,0,8,3,3,103,0,0,0,0,5,205,3,3,88,20,
	162,3,58,33,0,0,0,0,39,3,3,101,0,0,0,0,
	52,3,3,136,49,0,0,0,0,35,3,3,3,74,0,0,
	0,0,0,130,3,3,145,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,
	0,0,0,0,0,106,2,2,2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,2,2,2,12,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,39,
	3,3,161,0,0,0,0,0,0,161,3,3,98,0,0,0,
	0,0,49,3,3,52,0,0,0,0,0,0,0,0,0,0,
	0,0,20,3,3,51,0,0,0,0,0,33,128,3,58,137,
	3,3,38,0,0,0,0,0,39,3,3,101,0,0,0,0,
	52,3,3,49,0,0,0,0,0,121,3,3,29,0,0,0,
	0,0,0,92,3,3,39,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,
	0,0,0,0,0,160,2,2,2,2,2,2,2,2,2,61,
	153,203,203,203,203,203,203,203,203,153,61,2,2,2,2,2,
	2,2,2,2,2,2,62,176,203,203,203,203,203,203,203,203,
	203,153,50,2,2,2,2,2,2,2,2,2,96,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,39,
	3,3,37,0,0,0,0,0,0,37,3,3,123,0,0,0,
	0,0,14,3,3,52,0,0,0,0,0,0,0,14,88,29,
	53,19,3,3,3,51,0,0,0,0,0,0,38,3,3,3,
	3,92,0,0,0,0,0,0,39,3,3,101,0,0,0,0,
	52,3,3,14,0,0,0,0,0,110,3,3,29,0,0,0,
	0,0,0,101,3,3,39,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,
	0,0,0,0,80,16,2,2,2,2,2,2,2,2,146,3,
	3,3,3,3,3,3,3,3,3,3,3,182,2,2,2,2,
	2,2,2,2,2,62,213,3,3,3,3,3,3,3,3,3,
	3,3,3,176,2,2,2,2,2,2,2,2,97,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,39,
	3,3,37,0,0,0,0,0,0,37,3,3,123,0,0,0,
	0,0,14,3,3,52,0,0,0,0,0,44,37,30,3,3,
	3,3,3,3,3,51,0,0,0,0,0,0,0,83,3,3,
	19,8,0,0,0,0,0,0,39,3,3,101,0,0,0,0,
	52,3,3,14,0,0,0,0,0,110,3,3,29,0,0,0,
	0,0,0,101,3,3,39,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,
	0,0,0,0,12,2,2,2,2,2,2,2,2,61,3,3,
	3,3,3,3,3,3,3,3,3,3,3,3,176,2,2,2,
	2,2,2,2,2,146,3,3,3,3,3,3,3,3,3,3,
	3,3,3,234,117,2,2,2,2,2,2,2,2,183,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,39,
	3,3,37,0,0,0,0,0,0,37,3,3,123,0,0,0,
	0,0,14,3,3,52,0,0,0,0,98,58,3,3,58,29,
	209,135,20,3,3,51,0,0,0,0,0,0,5,137,3,3,
	3,123,0,0,0,0,0,0,39,3,3,101,0,0,0,0,
	52,3,3,14,0,0,0,0,0,110,3,3,29,0,0,0,
	0,0,0,101,3,3,39,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,
	0,0,0,141,2,2,2,2,2,2,2,2,2,153,3,3,
	3,3,3,3,3,3,3,3,3,3,3,3,154,117,2,2,
	2,2,2,2,61,3,3,3,3,3,3,3,3,3,3,3,
	3,3,3,3,50,2,2,2,2,2,2,2,2,97,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,39,
	3,3,37,0,0,0,0,0,0,37,3,3,123,0,0,0,
	0,0,14,3,3,52,0,0,0,45,85,3,3,35,47,0,
	0,0,0,3,3,51,0,0,0,0,0,0,87,3,3,3,
	3,56,14,0,0,0,0,0,39,3,3,101,0,0,0,0,
	52,3,3,14,0,0,0,0,0,110,3,3,29,0,0,0,
	0,0,0,101,3,3,39,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,
	0,0,0,204,2,2,2,2,2,2,2,2,2,203,3,3,
	3,3,3,3,3,3,3,3,3,3,3,3,3,153,2,2,
	2,2,2,225,213,3,3,3,3,3,3,3,3,3,3,3,
	3,3,3,3,50,2,2,2,2,2,2,2,2,16,152,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,39,
	3,3,37,0,0,0,0,0,0,37,3,3,123,0,0,0,
	0,0,14,3,3,52,0,0,0,75,3,3,35,0,0,0,
	0,0,0,3,3,51,0,0,0,0,0,45,85,3,156,82,
	3,3,166,0,0,0,0,0,39,3,3,101,0,0,0,0,
	52,3,3,14,0,0,0,0,0,110,3,3,29,0,0,0,
	0,0,0,101,3,3,39,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,
	0,0,0,18,2,2,2,2,2,2,2,2,2,203,3,3,
	3,3,3,3,3,3,3,3,3,3,3,3,3,3,62,2,
	2,2,2,176,3,3,3,3,3,3,3,3,3,3,3,3,
	3,3,3,3,50,2,2,2,2,2,2,2,2,2,149,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,39,
	3,3,37,0,0,0,0,0,0,37,3,3,123,0,0,0,
	0,0,14,3,3,52,0,0,0,83,3,3,25,0,0,0,
	0,0,8,3,3,51,0,0,0,0,23,36,3,3,22,7,
	52,3,3,43,0,0,0,0,39,3,3,101,0,0,0,0,
	52,3,3,14,0,0,0,0,0,110,3,3,29,0,0,0,
	0,0,0,101,3,3,39,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,
	0,0,152,16,2,2,2,2,2,2,2,2,2,203,3,3,
	3,3,3,3,168,168,168,61,3,3,3,3,3,3,182,2,
	2,2,77,30,3,3,3,3,3,201,168,168,168,222,3,3,
	3,3,3,3,50,2,2,2,2,2,2,2,2,2,86,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,39,
	3,3,37,0,0,0,0,0,0,37,3,3,123,0,0,0,
	0,0,14,3,3,52,0,0,0,161,3,3,38,0,0,0,
	0,135,102,3,3,51,0,0,0,0,21,3,3,84,0,0,
	39,3,3,162,20,0,0,0,39,3,3,101,0,0,0,0,
	52,3,3,14,0,0,0,0,0,110,3,3,29,0,0,0,
	0,0,0,101,3,3,39,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,
	0,0,149,2,2,2,2,2,2,2,2,2,2,203,3,3,
	3,3,3,3,2,2,2,2,203,3,3,3,3,3,3,77,
	2,2,153,3,3,3,3,3,3,168,2,2,2,168,3,3,
	3,3,3,3,50,2,2,2,2,2,2,2,2,2,138,27,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,39,
	3,3,37,0,0,0,0,0,0,37,3,3,123,0,0,0,
	0,0,14,3,3,52,0,0,0,35,3,3,197,35,98,87,
	92,3,3,30,3,51,0,0,0,177,3,3,122,7,0,0,
	0,187,3,3,169,5,0,0,39,3,3,101,0,0,0,0,
	52,3,3,14,0,0,0,0,0,110,3,3,29,0,0,0,
	0,0,0,101,3,3,39,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,
	0,0,148,2,2,2,2,2,2,2,2,2,2,203,3,3,
	3,3,3,3,2,2,2,2,62,94,3,3,3,3,203,2,
	2,62,3,3,3,3,3,3,182,2,2,2,2,168,3,3,
	3,3,3,3,50,2,2,2,2,2,2,2,2,2,2,167,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,39,
	3,3,37,0,0,0,0,0,0,37,3,3,123,0,0,0,
	0,0,14,3,3,52,0,0,0,7,56,3,3,3,3,3,
	3,105,174,166,3,51,0,0,7,52,3,3,98,0,0,0,
	0,23,36,3,3,75,0,0,39,3,3,101,0,0,0,0,
	52,3,3,14,0,0,0,0,0,110,3,3,29,0,0,0,
	0,0,0,101,3,3,39,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,
	0,0,48,2,2,2,2,2,2,2,2,2,2,203,3,3,
	3,3,3,3,2,2,2,2,2,222,3,3,3,234,62,2,
	2,182,3,3,3,3,3,3,50,2,2,2,2,168,3,3,
	3,3,3,3,50,2,2,2,2,2,2,2,2,2,2,140,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,72,
	51,51,82,0,0,0,0,0,0,82,51,51,177,0,0,0,
	0,0,47,51,51,136,0,0,0,0,33,83,94,3,3,143,
	34,45,0,87,51,103,0,0,69,51,51,84,0,0,0,0,
	0,0,64,130,51,56,99,0,72,51,51,29,0,0,0,0,
	136,51,51,47,0,0,0,0,0,123,51,51,84,0,0,0,
	0,0,0,29,51,51,72,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,
	0,0,16,2,2,2,2,2,2,2,2,2,2,203,3,3,
	3,3,3,3,2,2,2,2,2,117,213,3,3,222,2,2,
	50,3,3,3,3,3,3,203,2,2,2,2,2,168,3,3,
	3,3,3,3,50,2,2,2,2,2,2,2,2,2,2,160,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,4,25,14,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,
	0,27,2,2,2,2,2,2,2,2,2,2,2,203,3,3,
	3,3,3,3,2,2,2,2,2,2,176,3,233,117,2,2,
	146,3,3,3,3,3,94,62,2,2,2,2,2,168,3,3,
	3,3,3,3,50,2,2,2,2,2,2,2,2,2,2,86,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,
	0,89,2,2,2,2,2,2,2,2,2,2,2,203,3,3,
	3,3,3,3,2,2,2,2,2,2,2,206,176,2,2,61,
	3,3,3,3,3,3,222,2,2,2,2,2,2,168,3,3,
	3,3,3,3,50,2,2,2,2,2,2,2,2,2,2,158,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,
	0,108,2,2,2,2,2,2,2,2,2,2,2,203,3,3,
	3,3,3,3,2,2,2,2,2,2,2,50,2,2,2,221,
	3,3,3,3,3,213,117,2,2,2,2,2,2,168,3,3,
	3,3,3,3,50,2,2,2,2,2,2,2,2,2,2,41,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,38,35,35,7,0,0,0,0,0,0,0,0,0,0,0,
	0,
	0,80,2,2,2,2,2,2,2,2,2,2,2,203,3,3,
	3,3,3,3,2,2,2,2,2,2,2,2,2,2,176,3,
	3,3,3,3,3,176,2,2,2,2,2,2,2,168,3,3,
	3,3,3,3,50,2,2,2,2,2,2,2,2,2,2,2,
	27,0,0,0,0,0,0,0,0,0,0,0,0,0,0,14,
	166,143,26,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,36,3,3,8,0,0,0,0,0,0,0,0,0,0,0,
	0,
	0,80,2,2,2,2,2,2,2,2,2,2,2,203,3,3,
	3,3,3,3,2,2,2,2,2,2,2,2,2,117,30,3,
	3,3,3,3,206,2,2,2,2,2,2,2,2,168,3,3,
	3,3,3,3,50,2,2,2,2,2,2,2,2,2,2,2,
	89,0,0,0,0,0,0,0,0,0,0,0,0,0,0,75,
	3,3,175,5,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,11,11,4,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,5,11,11,
	5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,36,3,3,8,0,0,0,0,0,0,0,0,0,0,0,
	0,
	0,141,2,2,2,2,2,2,2,2,2,2,2,203,3,3,
	3,3,3,3,2,2,2,2,2,2,2,2,2,153,3,3,
	3,3,3,3,176,2,2,2,2,2,2,2,2,168,3,3,
	3,3,3,3,50,2,2,2,2,2,2,2,2,2,2,16,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,174,
	3,3,36,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,85,3,52,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,26,3,3,
	21,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,36,3,3,8,0,0,0,0,0,0,0,0,0,0,0,
	0,
	0,106,2,2,2,2,2,2,2,2,2,2,2,203,3,3,
	3,3,3,3,2,2,2,2,2,2,2,2,62,3,3,3,
	3,3,3,3,146,2,2,2,2,2,2,2,2,168,3,3,
	3,3,3,3,50,2,2,2,2,2,2,2,2,2,2,126,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,23,
	74,82,45,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,85,3,52,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,26,3,3,
	21,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,36,3,3,8,0,0,0,0,0,0,0,0,0,0,0,
	0,
	0,151,2,2,2,2,2,2,2,2,2,2,2,203,3,3,
	3,3,3,3,2,2,2,2,2,2,2,2,203,3,3,3,
	3,3,3,3,3,61,2,2,2,2,2,2,2,168,3,3,
	3,3,3,3,50,2,2,2,2,2,2,2,2,2,2,18,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,85,3,52,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,26,3,3,
	21,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,36,3,3,8,0,0,0,0,0,0,0,0,0,0,0,
	0,
	0,115,2,2,2,2,2,2,2,2,2,2,2,203,3,3,
	3,3,3,3,2,2,2,2,2,2,2,50,3,3,3,3,
	3,3,3,3,3,206,2,2,2,2,2,2,2,168,3,3,
	3,3,3,3,50,2,2,2,2,2,2,2,2,2,2,107,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,85,3,52,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,26,3,3,
	21,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,36,3,3,8,0,0,0,0,0,0,0,0,0,0,0,
	0,
	0,0,41,2,2,2,2,2,2,2,2,2,2,203,3,3,
	3,3,3,3,2,2,2,2,2,2,2,146,3,3,3,3,
	3,3,3,3,3,3,176,2,2,2,2,2,2,168,3,3,
	3,3,3,3,50,2,2,2,2,2,2,2,2,2,2,144,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11,
	25,25,20,0,0,0,0,46,25,14,0,0,0,11,98,74,
	135,14,0,0,0,0,8,25,25,30,3,186,25,25,25,20,
	0,0,0,0,0,0,14,98,74,98,14,0,0,0,0,0,
	0,0,0,0,0,14,22,88,38,22,11,0,0,0,11,39,
	0,0,14,25,99,0,0,0,5,39,172,0,0,0,0,7,
	145,26,74,192,110,20,0,0,0,0,0,25,25,74,3,3,
	34,25,25,25,7,0,0,0,0,0,0,33,57,38,72,23,
	0,0,0,0,0,0,0,0,0,0,0,11,72,121,33,5,
	0,36,3,3,8,0,0,0,0,0,0,0,0,0,0,0,
	0,
	0,0,13,2,2,2,2,2,2,2,2,2,2,203,3,3,
	3,3,3,3,2,2,2,2,2,2,168,3,3,3,3,3,
	3,3,3,3,3,3,154,117,2,2,2,2,2,168,3,3,
	3,3,3,3,50,2,2,2,2,2,2,2,2,2,2,67,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,39,
	3,3,37,0,0,0,0,56,3,21,0,25,65,30,3,3,
	3,119,172,0,0,0,29,3,3,3,3,3,3,3,3,37,
	0,0,0,0,55,92,3,3,3,3,3,136,8,0,0,0,
	0,0,0,7,35,58,3,3,3,3,122,38,38,161,58,58,
	5,0,35,3,128,0,0,135,143,3,19,0,11,88,65,30,
	3,3,3,3,3,30,82,47,0,0,0,19,3,3,3,3,
	3,3,3,3,26,0,0,0,0,22,186,3,3,3,3,85,
	21,5,0,0,0,0,0,0,0,25,136,3,3,3,3,128,
	185,19,3,3,8,0,0,0,0,0,0,0,0,0,0,0,
	0,
	0,0,139,2,2,2,2,2,2,2,2,2,2,203,3,3,
	3,3,3,3,2,2,2,2,2,2,206,3,3,3,3,3,
	3,3,3,3,3,3,3,153,2,2,2,2,2,168,3,3,
	3,3,3,3,50,2,2,2,2,2,2,2,2,2,2,80,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,39,
	3,3,37,0,0,0,0,56,3,163,88,30,3,3,3,3,
	3,3,85,25,0,0,29,3,3,3,3,3,3,3,3,37,
	0,0,0,39,130,3,3,30,52,30,3,3,122,64,0,0,
	0,0,5,163,3,3,19,163,169,30,3,3,3,3,3,3,
	33,0,35,3,3,20,110,30,3,3,3,20,7,3,3,3,
	3,3,3,3,3,3,3,34,0,0,0,19,3,3,3,3,
	3,3,3,3,26,0,0,0,87,3,3,3,102,56,3,3,
	3,163,7,0,0,0,0,0,81,58,3,3,3,3,3,3,
	3,3,3,3,8,0,0,0,0,0,0,0,0,0,0,0,
	0,
	0,0,59,2,2,2,2,2,2,2,2,2,2,203,3,3,
	3,3,3,3,2,2,2,2,2,176,3,3,3,3,3,3,
	176,201,3,3,3,3,3,3,62,2,2,2,2,168,3,3,
	3,3,3,3,50,2,2,2,2,2,2,2,2,2,157,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,39,
	3,3,37,0,0,0,0,56,3,3,3,3,93,209,39,21,
	19,3,3,84,0,0,64,110,110,30,3,122,110,110,110,64,
	0,0,23,52,3,3,35,5,0,23,35,3,3,155,0,0,
	0,0,75,3,3,169,14,0,0,46,186,3,3,83,88,121,
	7,0,35,3,3,35,105,3,3,83,75,14,0,175,122,69,
	110,25,7,22,21,3,3,3,25,0,0,98,110,69,3,3,
	37,110,110,110,55,0,0,39,3,3,130,123,0,0,8,65,
	3,3,35,0,0,0,0,46,85,3,3,37,110,33,39,81,
	163,3,3,3,8,0,0,0,0,0,0,0,0,0,0,0,
	0,
	0,0,0,124,2,2,2,2,2,2,2,2,2,203,3,3,
	3,3,3,3,2,2,2,2,117,154,3,3,3,3,3,221,
	2,212,3,3,3,3,3,3,203,2,2,2,2,168,3,3,
	3,3,3,3,50,2,2,2,2,2,2,2,2,2,139,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,39,
	3,3,37,0,0,0,0,56,3,3,94,88,0,0,0,0,
	35,3,3,65,0,0,0,0,0,85,3,52,0,0,0,0,
	0,0,75,3,3,21,0,0,0,0,0,93,3,3,121,0,
	0,0,70,3,3,123,0,0,0,0,75,3,3,21,0,0,
	0,0,35,3,3,3,3,53,25,0,0,0,0,25,5,0,
	0,0,0,0,0,37,3,3,26,0,0,0,0,26,3,3,
	21,0,0,0,0,0,0,185,3,3,22,0,0,0,0,55,
	30,3,102,7,0,0,0,129,3,3,35,0,0,0,0,0,
	0,36,3,3,8,0,0,0,0,0,0,0,0,0,0,0,
	0,
	0,0,0,160,2,2,2,2,2,2,2,2,2,203,3,3,
	3,3,3,3,2,2,2,2,153,3,3,3,3,3,3,61,
	2,2,182,3,3,3,3,3,3,50,2,2,2,168,3,3,
	3,3,3,3,50,2,2,2,2,2,2,2,2,2,59,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,39,
	3,3,37,0,0,0,0,56,3,3,98,0,0,0,0,0,
	44,3,3,36,0,0,0,0,0,85,3,52,0,0,0,0,
	0,0,56,3,30,47,0,0,0,0,0,57,3,3,92,0,
	0,4,85,3,130,5,0,0,0,0,55,94,3,70,0,0,
	0,0,35,3,3,3,156,49,0,0,0,0,0,0,0,0,
	0,0,0,0,0,87,3,3,75,0,0,0,0,26,3,3,
	21,0,0,0,0,0,39,3,3,163,0,0,0,0,0,0,
	161,3,3,81,0,0,44,3,3,56,5,0,0,0,0,0,
	0,36,3,3,8,0,0,0,0,0,0,0,0,0,0,0,
	0,
	0,0,0,167,2,2,2,2,2,2,2,2,2,203,3,3,
	3,3,3,3,2,2,2,62,3,3,3,3,3,3,146,2,
	2,2,215,3,3,3,3,3,3,146,2,2,2,168,3,3,
	3,3,3,3,50,2,2,2,2,2,2,2,2,10,5,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,39,
	3,3,37,0,0,0,0,56,3,3,11,0,0,0,0,0,
	8,3,3,36,0,0,0,0,0,85,3,52,0,0,0,0,
	0,7,3,3,103,123,123,123,123,123,123,135,85,3,156,0,
	0,5,119,3,175,5,0,0,0,0,33,3,3,70,0,0,
	0,0,35,3,3,102,99,0,0,0,0,0,0,0,0,0,
	0,7,72,174,21,36,3,3,35,0,0,0,0,26,3,3,
	21,0,0,0,0,0,38,3,3,84,123,123,123,123,123,123,
	69,3,3,69,0,0,174,3,3,35,0,0,0,0,0,0,
	0,36,3,3,8,0,0,0,0,0,0,0,0,0,0,0,
	0,
	0,0,0,27,210,2,2,2,2,2,2,2,2,203,3,3,
	3,3,3,3,2,2,2,203,3,3,3,3,3,3,50,2,
	2,2,2,203,3,3,3,3,3,3,168,2,2,168,3,3,
	3,3,3,3,50,2,2,2,2,2,2,2,2,144,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,39,
	3,3,37,0,0,0,0,56,3,3,11,0,0,0,0,0,
	8,3,3,36,0,0,0,0,0,85,3,52,0,0,0,0,
	0,54,3,3,3,3,3,3,3,3,3,3,3,3,30,5,
	0,0,29,3,3,98,0,0,0,0,69,3,3,114,0,0,
	0,0,35,3,3,75,0,0,0,0,0,0,0,0,11,57,
	92,94,3,3,3,3,3,3,35,0,0,0,0,26,3,3,
	21,0,0,0,0,0,21,3,3,3,3,3,3,3,3,3,
	3,3,3,216,0,0,21,3,3,57,0,0,0,0,0,0,
	0,36,3,3,8,0,0,0,0,0,0,0,0,0,0,0,
	0,
	0,0,0,0,67,2,2,2,2,2,2,2,2,203,3,3,
	3,3,3,3,2,2,50,3,3,3,3,3,3,182,2,2,
	2,2,2,77,234,3,3,3,3,3,206,2,2,168,3,3,
	3,3,3,3,50,2,2,2,2,2,2,2,2,106,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,39,
	3,3,37,0,0,0,0,56,3,3,11,0,0,0,0,0,
	8,3,3,36,0,0,0,0,0,85,3,52,0,0,0,0,
	0,57,3,3,85,162,162,162,162,162,162,162,162,162,162,49,
	0,0,26,3,3,53,33,0,0,22,119,3,105,45,0,0,
	0,0,35,3,3,75,0,0,0,0,0,0,0,39,119,3,
	3,3,3,156,83,169,3,3,35,0,0,0,0,26,3,3,
	21,0,0,0,0,0,37,3,3,58,19,19,19,19,19,19,
	19,19,19,129,0,0,101,3,3,54,0,0,0,0,0,0,
	0,36,3,3,8,0,0,0,0,0,0,0,0,0,0,0,
	0,
	0,0,0,0,32,68,2,2,2,2,2,2,2,203,3,3,
	3,3,3,3,2,2,146,3,3,3,3,3,3,62,2,2,
	2,2,2,2,71,3,3,3,3,3,3,176,2,168,3,3,
	3,3,3,3,50,2,2,2,2,2,2,2,116,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,39,
	3,3,37,0,0,0,0,56,3,3,11,0,0,0,0,0,
	8,3,3,36,0,0,0,0,0,85,3,52,0,0,0,0,
	0,22,3,3,29,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,88,3,3,3,52,130,3,3,3,81,0,0,0,
	0,0,35,3,3,75,0,0,0,0,0,0,22,128,3,3,
	136,57,11,0,0,75,3,3,35,0,0,0,0,26,3,3,
	21,0,0,0,0,0,114,3,3,110,0,0,0,0,0,0,
	0,0,0,0,0,0,173,3,3,177,0,0,0,0,0,0,
	0,36,3,3,8,0,0,0,0,0,0,0,0,0,0,0,
	0,
	0,0,0,0,0,79,2,2,2,2,2,2,2,61,153,153,
	153,153,153,153,2,62,153,153,153,153,153,153,61,2,2,2,
	2,2,2,2,117,153,153,153,153,153,153,71,2,215,153,153,
	153,153,153,153,62,2,2,2,2,2,2,210,27,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,39,
	3,3,37,0,0,0,0,56,3,3,11,0,0,0,0,0,
	8,3,3,36,0,0,0,0,0,85,3,52,0,0,0,0,
	0,49,3,3,70,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,35,3,3,3,3,3,65,64,0,0,0,0,
	0,0,35,3,3,75,0,0,0,0,0,0,205,3,3,75,
	0,0,0,0,0,75,3,3,35,0,0,0,0,26,3,3,
	21,0,0,0,0,0,88,3,3,75,0,0,0,0,0,0,
	0,0,0,0,0,0,84,3,3,43,0,0,0,0,0,0,
	0,36,3,3,8,0,0,0,0,0,0,0,0,0,0,0,
	0,
	0,0,0,0,0,0,97,2,2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,2,2,2,67,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,39,
	3,3,37,0,0,0,0,56,3,3,11,0,0,0,0,0,
	8,3,3,36,0,0,0,0,0,85,3,52,0,0,0,0,
	0,0,19,3,105,49,0,0,0,0,0,0,0,0,0,0,
	0,0,0,110,30,3,21,22,64,11,0,0,0,0,0,0,
	0,0,35,3,3,75,0,0,0,0,0,11,30,3,70,0,
	0,0,0,0,0,75,3,3,35,0,0,0,0,26,3,3,
	21,0,0,0,0,0,98,3,3,92,0,0,0,0,0,0,
	0,0,0,0,0,0,74,3,3,82,0,0,0,0,0,0,
	55,51,3,3,8,0,0,0,0,0,0,0,0,0,0,0,
	0,
	0,0,0,0,0,0,59,16,2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,2,2,68,32,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,39,
	3,3,37,0,0,0,0,56,3,3,11,0,0,0,0,0,
	8,3,3,36,0,0,0,0,0,58,3,58,11,0,0,0,
	0,0,166,3,3,84,0,0,0,0,0,0,0,135,104,0,
	0,0,0,163,3,3,75,8,0,0,0,0,0,0,0,0,
	0,0,35,3,3,75,0,0,0,0,0,45,3,3,137,0,
	0,0,0,0,25,36,3,3,35,0,0,0,0,121,3,3,
	161,0,0,0,0,0,14,19,3,3,123,0,0,0,0,0,
	0,23,35,43,0,0,39,3,3,30,8,0,0,0,0,55,
	103,3,3,3,8,0,0,123,69,69,121,69,14,0,75,11,
	0,
	0,0,0,0,0,0,0,60,2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,2,41,80,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,39,
	3,3,37,0,0,0,0,56,3,3,11,0,0,0,0,0,
	8,3,3,36,0,0,0,0,0,36,3,3,187,8,0,5,
	0,0,20,58,3,3,82,14,0,0,47,98,166,3,122,0,
	0,0,0,21,3,3,3,3,56,161,75,33,0,0,0,0,
	0,0,35,3,3,75,0,0,0,0,0,7,3,3,3,22,
	0,0,14,38,128,3,3,3,35,0,0,0,0,25,3,3,
	58,26,11,0,5,0,0,88,3,3,19,38,5,0,0,33,
	43,143,3,21,0,0,0,163,3,3,52,64,0,49,38,143,
	3,3,3,3,8,0,0,11,81,74,14,52,74,45,52,14,
	0,
	0,0,0,0,0,0,0,0,107,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,16,167,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,39,
	3,3,37,0,0,0,0,56,3,3,11,0,0,0,0,0,
	8,3,3,36,0,0,0,0,0,82,3,3,3,3,30,163,
	0,0,0,209,3,3,3,3,156,224,3,3,3,3,122,5,
	0,0,0,177,30,3,3,3,3,3,3,3,53,75,55,0,
	0,0,35,3,3,75,0,0,0,0,0,0,83,3,3,3,
	143,103,3,3,3,37,3,3,35,0,0,0,0,23,51,3,
	3,3,30,94,38,0,0,5,136,3,3,3,30,155,102,3,
	3,3,3,104,0,0,0,45,30,3,3,3,102,3,3,3,
	52,161,3,3,8,0,0,0,26,38,11,37,34,21,69,14,
	0,
	0,0,0,0,0,0,0,0,27,202,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,60,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,39,
	3,3,37,0,0,0,0,56,3,3,11,0,0,0,0,0,
	8,3,3,36,0,0,0,0,0,14,156,3,3,3,3,122,
	0,0,0,0,110,56,3,3,3,3,3,3,128,35,7,0,
	0,5,75,30,3,65,98,74,34,155,94,3,3,3,143,49,
	0,0,35,3,3,75,0,0,0,0,0,0,8,36,3,3,
	3,3,3,19,121,4,3,3,35,0,0,0,0,0,135,30,
	3,3,3,3,21,0,0,0,4,69,30,3,3,3,3,3,
	3,224,121,0,0,0,0,0,72,156,3,3,3,3,3,179,
	49,174,3,3,8,0,0,0,26,38,11,37,209,37,88,14,
	0,
	0,0,0,0,0,0,0,0,0,106,126,2,2,2,2,2,
	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,193,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,55,
	88,88,98,0,0,0,0,81,88,88,5,0,0,0,0,0,
	7,88,88,57,0,0,0,0,0,0,5,57,21,166,84,69,
	0,0,0,0,0,7,57,69,37,34,75,110,14,0,0,0,
	0,209,3,3,87,0,0,0,0,0,49,88,52,3,3,35,
	0,0,44,88,88,64,0,0,0,0,0,0,0,5,174,84,
	37,87,22,7,0,0,174,88,44,0,0,0,0,0,0,55,
	75,84,166,104,172,0,0,0,0,0,25,38,114,161,114,38,
	22,5,0,0,0,0,0,0,0,7,43,114,37,74,45,5,
	0,20,88,88,7,0,0,0,20,25,5,22,14,45,25,4,
	0,
	0,0,0,0,0,0,0,0,0,0,112,124,2,2,2,2,
	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,86,32,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,36,3,186,5,0,0,0,0,0,0,0,39,3,3,37,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,
	0,0,0,0,0,0,0,0,0,0,0,106,13,2,2,2,
	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
	2,2,2,2,2,139,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	7,3,3,70,0,0,0,0,0,0,0,0,39,3,3,75,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,
	0,0,0,0,0,0,0,0,0,0,0,0,27,107,2,2,
	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
	2,2,2,138,149,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,40,3,3,166,123,14,0,0,23,145,88,119,3,30,33,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,140,2,
	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
	2,2,126,59,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,64,56,3,3,3,3,175,36,30,3,3,3,19,22,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,96,
	13,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
	16,160,152,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,55,187,224,3,3,3,3,3,3,52,69,20,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,149,126,2,2,2,2,2,2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,12,
	80,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,8,44,98,135,64,55,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,32,204,41,2,2,2,2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,2,2,2,2,2,13,96,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,27,79,193,41,2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,2,2,157,139,59,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,32,111,144,48,16,2,2,2,2,
	2,2,2,2,2,2,2,18,189,131,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,27,152,141,112,
	96,59,80,108,89,32,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0
	};