/*  GIMP header image file format (INDEXED): /home/alpha/MAXIM/Images/selectionslideshow/demopack/rotating-logo-medium/OUT/medium-logo-002.h  */

static unsigned int width = 64;
static unsigned int height = 64;

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
	5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
	5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
	5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
	5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
	5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
	5,5,5,5,5,5,5,5,27,59,189,90,86,18,10,2,
	16,126,113,107,140,218,131,32,5,5,5,5,5,5,5,5,
	5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
	5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
	5,5,5,5,5,27,111,160,126,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,18,140,131,5,5,5,5,5,5,
	5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
	5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
	5,5,5,108,90,48,2,2,2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,2,2,158,67,27,5,5,5,
	5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
	5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
	5,220,140,210,2,2,2,2,2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,2,2,2,2,158,111,5,5,
	5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
	5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
	167,48,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,2,2,2,2,2,2,12,131,
	5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
	5,5,5,5,5,5,5,5,5,5,5,5,5,5,106,86,
	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,210,
	189,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
	5,5,5,5,5,5,5,5,5,5,5,5,5,131,18,2,
	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
	2,144,27,5,5,5,5,5,5,5,5,5,5,5,5,5,
	5,5,5,5,5,5,5,5,5,5,5,5,59,158,2,2,
	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
	2,2,107,106,5,5,5,5,5,5,5,5,5,5,5,5,
	5,5,5,5,5,5,5,5,5,5,5,79,68,2,2,2,
	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
	2,2,2,12,141,5,5,5,5,5,5,5,5,5,5,5,
	5,5,5,5,5,5,5,5,5,5,79,157,2,2,2,2,
	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
	2,2,2,2,12,108,5,5,5,5,5,5,5,5,5,5,
	5,5,5,5,5,5,5,5,5,59,113,2,2,2,2,2,
	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
	2,2,2,2,2,144,220,5,5,5,5,5,5,5,5,5,
	5,5,5,5,5,5,5,5,106,160,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
	2,2,2,2,2,210,223,5,5,5,5,5,5,5,5,5,
	5,5,5,5,5,5,5,27,60,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,157,167,5,5,5,5,5,5,5,5,
	5,5,5,5,5,5,5,79,210,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,199,112,5,5,5,5,5,5,5,
	5,5,5,5,5,5,131,86,2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,60,27,5,5,5,5,5,5,
	5,5,5,5,5,27,218,2,2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,18,59,5,5,5,5,5,5,
	5,5,5,5,5,108,12,2,2,2,2,2,2,2,2,212,
	153,203,203,203,203,203,203,203,203,176,62,2,2,2,2,2,
	2,2,2,2,117,50,222,203,203,203,203,203,203,203,203,153,
	215,2,2,2,2,2,2,2,2,140,27,5,5,5,5,5,
	5,5,5,5,32,149,2,2,2,2,2,2,2,2,203,94,
	3,31,3,31,3,31,3,31,3,3,146,215,2,2,2,2,
	2,2,2,117,61,154,3,31,3,31,31,31,31,3,31,3,
	154,168,2,2,2,2,2,2,2,157,80,5,5,5,5,5,
	5,5,5,5,108,18,2,2,2,2,2,2,2,50,221,3,
	3,31,3,31,3,31,3,31,3,31,3,203,77,2,2,2,
	2,2,2,62,206,3,3,31,3,3,3,3,3,31,3,31,
	3,146,117,2,2,2,2,2,2,2,140,27,5,5,5,5,
	5,5,5,32,111,2,2,2,2,2,2,2,2,176,128,31,
	3,31,3,31,3,234,3,3,31,3,3,31,50,2,2,2,
	2,2,117,71,3,3,31,3,31,31,31,31,31,3,31,3,
	234,201,62,2,2,2,2,2,2,2,158,108,5,5,5,5,
	5,5,5,27,144,2,2,2,2,2,2,2,2,176,154,3,
	31,3,31,3,3,3,3,234,3,31,3,31,203,77,2,2,
	2,2,215,128,3,3,31,3,3,3,3,3,3,31,3,31,
	3,201,62,2,2,2,2,2,2,2,2,96,5,5,5,5,
	5,5,5,152,68,2,2,2,2,2,2,2,2,71,154,3,
	31,3,3,3,3,234,3,3,3,3,31,3,234,212,2,2,
	2,117,153,3,31,3,3,3,3,3,3,234,3,3,31,3,
	234,201,62,2,2,2,2,2,2,2,2,140,27,5,5,5,
	5,5,5,112,2,2,2,2,2,2,2,2,2,176,154,3,
	31,3,234,221,212,168,168,203,3,3,234,3,3,146,77,2,
	2,215,94,3,31,3,3,233,222,168,168,71,233,3,3,31,
	3,201,62,2,2,2,2,2,2,2,2,113,106,5,5,5,
	5,5,32,189,2,2,2,2,2,2,2,2,2,71,154,3,
	31,3,3,146,2,2,2,212,201,3,3,3,3,234,215,2,
	117,203,3,31,3,3,3,203,77,2,2,50,221,3,31,3,
	234,201,62,2,2,2,2,2,2,2,2,16,131,5,5,5,
	5,5,27,12,2,2,2,2,2,2,2,2,2,176,154,3,
	31,3,3,146,2,2,2,117,222,234,3,3,3,182,117,2,
	215,3,3,31,3,3,201,168,2,2,2,50,201,234,3,31,
	3,201,62,2,2,2,2,2,2,2,2,2,218,5,5,5,
	5,5,27,48,2,2,2,2,2,2,2,2,2,71,154,3,
	31,3,234,146,2,2,2,2,50,146,3,3,234,212,2,2,
	182,3,31,3,3,234,203,77,2,2,2,50,221,3,31,3,
	234,201,62,2,2,2,2,2,2,2,2,2,144,32,5,5,
	5,5,27,16,2,2,2,2,2,2,2,2,2,176,154,3,
	31,3,3,146,2,2,2,2,2,71,94,234,203,77,2,215,
	3,3,3,31,3,221,61,2,2,2,2,50,201,234,3,31,
	3,201,62,2,2,2,2,2,2,2,2,2,107,27,5,5,
	5,5,106,2,2,2,2,2,2,2,2,2,2,71,154,3,
	31,3,234,146,2,2,2,2,2,50,146,128,50,2,2,182,
	3,94,3,3,234,203,117,2,2,2,2,50,221,3,31,3,
	234,201,62,2,2,2,2,2,2,2,2,2,97,27,5,5,
	5,5,108,2,2,2,2,2,2,2,2,2,2,176,154,3,
	31,3,3,146,2,2,2,2,2,2,222,153,77,2,212,94,
	3,3,3,234,201,168,2,2,2,2,2,50,201,234,3,31,
	3,201,62,2,2,2,2,2,2,2,2,2,157,27,5,5,
	5,5,80,2,2,2,2,2,2,2,2,2,2,71,154,3,
	31,3,3,146,2,2,2,2,2,2,62,117,2,2,146,3,
	31,3,3,94,203,117,2,2,2,2,2,50,221,3,31,3,
	234,201,62,2,2,2,2,2,2,2,2,2,41,27,5,5,
	5,5,59,2,2,2,2,2,2,2,2,2,2,71,154,234,
	3,31,3,146,2,2,2,2,2,2,2,2,2,61,128,3,
	3,31,3,201,212,2,2,2,2,2,2,50,221,234,3,31,
	3,201,62,2,2,2,2,2,2,2,2,2,2,106,5,5,
	5,5,59,2,2,2,2,2,2,2,2,2,2,71,154,3,
	31,3,3,146,2,2,2,2,2,2,2,2,117,146,94,3,
	31,3,234,203,2,2,2,2,2,2,2,50,201,3,31,3,
	234,201,62,2,2,2,2,2,2,2,2,2,2,108,5,5,
	5,5,112,2,2,2,2,2,2,2,2,2,2,176,154,3,
	31,3,234,146,2,2,2,2,2,2,2,2,176,233,3,3,
	31,3,233,168,2,2,2,2,2,2,2,50,221,234,3,31,
	3,201,62,2,2,2,2,2,2,2,2,2,16,220,5,5,
	5,5,131,2,2,2,2,2,2,2,2,2,2,71,154,3,
	31,3,3,146,2,2,2,2,2,2,2,77,146,3,31,3,
	31,3,94,153,2,2,2,2,2,2,2,50,201,3,31,3,
	234,201,62,2,2,2,2,2,2,2,2,2,126,27,5,5,
	5,5,106,2,2,2,2,2,2,2,2,2,2,176,154,3,
	31,3,3,146,2,2,2,2,2,2,2,176,233,3,3,31,
	3,31,3,201,50,2,2,2,2,2,2,50,221,234,3,31,
	3,201,62,2,2,2,2,2,2,2,2,2,13,27,5,5,
	5,5,106,2,2,2,2,2,2,2,2,2,2,71,154,3,
	31,3,234,146,2,2,2,2,2,2,77,146,3,31,3,31,
	3,31,3,234,153,2,2,2,2,2,2,50,221,3,31,3,
	234,201,62,2,2,2,2,2,2,2,2,2,86,27,5,5,
	5,5,27,41,2,2,2,2,2,2,2,2,2,176,154,3,
	31,3,3,146,2,2,2,2,2,2,71,154,234,3,3,31,
	3,31,3,31,201,212,2,2,2,2,2,50,221,234,3,31,
	3,201,62,2,2,2,2,2,2,2,2,2,107,32,5,5,
	5,5,27,157,2,2,2,2,2,2,2,2,2,71,154,3,
	31,3,3,146,2,2,2,2,2,215,182,3,3,31,31,3,
	31,3,31,3,234,153,2,2,2,2,2,50,221,3,31,3,
	234,201,62,2,2,2,2,2,2,2,2,2,140,32,5,5,
	5,5,32,160,2,2,2,2,2,2,2,2,2,71,154,234,
	3,31,3,146,2,2,2,2,2,176,154,3,3,3,3,3,
	3,3,31,3,31,201,212,2,2,2,2,50,221,234,3,31,
	3,201,62,2,2,2,2,2,2,2,2,2,111,5,5,5,
	5,5,5,167,2,2,2,2,2,2,2,2,2,71,154,3,
	31,3,3,146,2,2,2,2,215,146,3,31,3,3,3,176,
	201,3,3,31,3,3,153,117,2,2,2,50,221,3,31,3,
	234,201,62,2,2,2,2,2,2,2,2,126,106,5,5,5,
	5,5,5,106,138,2,2,2,2,2,2,2,2,176,154,3,
	3,31,3,146,2,2,2,2,71,234,3,31,3,3,213,117,
	168,3,3,3,31,3,201,212,2,2,2,50,221,234,3,31,
	3,201,62,2,2,2,2,2,2,2,2,107,220,5,5,5,
	5,5,5,220,107,2,2,2,2,2,2,2,2,71,154,3,
	31,3,3,146,2,2,2,50,146,3,31,3,3,234,176,2,
	117,182,3,3,3,3,3,153,77,2,2,50,221,3,31,3,
	234,201,62,2,2,2,2,2,2,2,2,79,5,5,5,5,
	5,5,5,32,189,2,2,2,2,2,2,2,2,176,154,3,
	3,3,3,146,2,2,117,71,3,3,31,3,3,201,77,2,
	2,212,234,3,234,3,3,233,168,2,2,50,221,234,3,3,
	234,201,62,2,2,2,2,2,2,2,210,131,5,5,5,5,
	5,5,5,5,112,210,2,2,2,2,2,2,2,71,128,3,
	234,3,234,146,2,2,50,146,3,234,3,3,234,61,2,2,
	2,117,182,3,3,3,3,234,153,77,2,50,221,234,3,3,
	234,201,62,2,2,2,2,2,2,2,107,106,5,5,5,5,
	5,5,5,5,220,144,2,2,2,2,2,2,2,71,154,3,
	3,3,3,146,2,117,71,234,3,3,3,3,146,77,2,2,
	2,2,50,31,3,3,3,3,154,168,2,50,221,3,3,3,
	3,201,62,2,2,2,2,2,2,2,79,5,5,5,5,5,
	5,5,5,5,5,59,48,2,2,2,2,2,2,71,154,234,
	234,234,234,146,2,50,221,3,234,3,234,234,168,2,2,2,
	2,2,77,153,234,234,3,234,234,203,62,50,221,234,234,234,
	234,201,62,2,2,2,2,2,2,148,106,5,5,5,5,5,
	5,5,5,5,5,220,144,2,2,2,2,2,2,50,71,153,
	153,153,222,176,117,50,153,222,153,222,153,176,77,2,2,2,
	2,2,2,215,222,153,222,153,222,71,62,62,71,153,222,153,
	222,71,77,2,2,2,2,2,210,167,5,5,5,5,5,5,
	5,5,5,5,5,5,59,157,2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,107,106,5,5,5,5,5,5,
	5,5,5,5,5,5,220,140,210,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,210,79,5,5,5,5,5,5,5,
	5,5,5,5,5,5,5,131,12,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,196,27,5,5,5,5,5,5,5,
	5,5,5,5,5,5,5,5,111,158,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,107,108,5,5,5,5,5,5,5,5,
	5,5,5,5,5,5,5,5,5,67,10,2,2,2,2,2,
	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
	2,2,2,2,2,113,59,5,5,5,5,5,5,5,5,5,
	5,5,5,5,5,5,5,5,5,32,150,210,2,2,2,2,
	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
	2,2,2,2,157,79,5,5,5,5,5,5,5,5,5,5,
	5,5,5,5,5,5,5,5,5,5,106,107,2,2,2,2,
	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
	2,2,2,10,67,5,5,5,5,5,5,5,5,5,5,5,
	5,5,5,5,5,5,5,5,5,5,5,220,144,210,2,2,
	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
	2,2,157,149,5,5,5,5,5,5,5,5,5,5,5,5,
	5,5,5,5,5,5,5,5,5,5,5,5,32,140,210,2,
	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
	2,157,111,5,5,5,5,5,5,5,5,5,5,5,5,5,
	5,5,5,5,5,5,5,5,5,5,5,5,5,5,218,210,
	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
	202,80,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
	5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,59,
	113,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,2,2,2,2,2,2,16,144,
	220,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
	5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
	5,149,126,2,2,2,2,2,2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,2,2,2,2,2,199,59,5,
	5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
	5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
	5,5,152,144,41,2,2,2,2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,2,2,2,157,79,32,5,5,
	5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
	5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
	5,5,5,5,108,189,113,2,2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,10,107,167,27,5,5,5,5,
	5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
	5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
	5,5,5,5,5,5,5,141,67,199,210,2,2,2,2,2,
	2,2,2,2,2,210,228,167,220,5,5,5,5,5,5,5,
	5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
	5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
	5,5,5,5,5,5,5,5,5,5,5,27,152,141,80,96,
	59,80,108,220,32,5,5,5,5,5,5,5,5,5,5,5,
	5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5
	};
