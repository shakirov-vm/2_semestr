enum ERRORS
{
	EMPTY_FILE = 1,
	UNOPEN     = 2,
	NOMEMALLOC = 3,
	FEWREAD    = 4,
	FEWWRITE   = 5,
};

const char* replaceable = "Hello world!";
const char* our = "Sapere aude!";

size_t FileSize(char* input);
void ErrorOpen(char* input);