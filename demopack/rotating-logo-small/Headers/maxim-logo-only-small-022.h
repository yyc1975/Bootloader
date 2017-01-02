/*  GIMP header image file format (INDEXED): /home/alpha/MAXIM/Images/selectionslideshow/demopack/rotating-logo-small-V2/OUT/maxim-logo-only-small-022.h  */

static unsigned int width = 22;
static unsigned int height = 22;

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
	5,5,5,5,5,5,5,5,5,5,112,108,5,5,5,5,
	5,5,5,5,5,5,
	5,5,5,5,5,5,5,5,5,139,2,2,149,5,5,5,
	5,5,5,5,5,5,
	5,5,5,5,5,5,5,5,59,2,2,2,48,220,5,5,
	5,5,5,5,5,5,
	5,5,5,5,5,5,5,5,12,2,2,2,2,140,5,5,
	5,5,5,5,5,5,
	5,5,5,5,5,5,5,108,10,2,2,2,2,13,5,5,
	5,5,5,5,5,5,
	5,5,5,5,5,5,5,167,2,2,2,2,2,10,108,5,
	5,5,5,5,5,5,
	5,5,5,5,5,5,5,116,168,146,62,168,146,62,167,5,
	5,5,5,5,5,5,
	5,5,5,5,5,5,5,12,222,3,176,203,3,212,140,5,
	5,5,5,5,5,5,
	5,5,5,5,5,5,5,13,222,153,153,146,203,212,144,5,
	5,5,5,5,5,5,
	5,5,5,5,5,5,5,157,71,168,146,71,222,212,228,5,
	5,5,5,5,5,5,
	5,5,5,5,5,5,5,10,222,212,146,62,71,168,12,5,
	5,5,5,5,5,5,
	5,5,5,5,5,5,5,2,222,50,153,50,71,212,12,5,
	5,5,5,5,5,5,
	5,5,5,5,5,5,5,10,222,50,203,176,71,212,148,5,
	5,5,5,5,5,5,
	5,5,5,5,5,5,5,157,222,212,206,203,71,168,90,5,
	5,5,5,5,5,5,
	5,5,5,5,5,5,5,18,222,61,146,146,222,212,116,5,
	5,5,5,5,5,5,
	5,5,5,5,5,5,5,107,222,153,222,146,153,212,67,5,
	5,5,5,5,5,5,
	5,5,5,5,5,5,5,67,168,61,50,168,176,62,59,5,
	5,5,5,5,5,5,
	5,5,5,5,5,5,5,59,2,2,2,2,2,10,220,5,
	5,5,5,5,5,5,
	5,5,5,5,5,5,5,220,10,2,2,2,2,12,5,5,
	5,5,5,5,5,5,
	5,5,5,5,5,5,5,5,139,2,2,2,2,167,5,5,
	5,5,5,5,5,5,
	5,5,5,5,5,5,5,5,152,10,2,2,12,32,5,5,
	5,5,5,5,5,5,
	5,5,5,5,5,5,5,5,5,59,13,148,108,5,5,5,
	5,5,5,5,5,5
	};
