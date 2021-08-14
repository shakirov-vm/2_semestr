#include <stdio.h>
#include <sys/mman.h>
#include <unistd.h>

// There more function, but I think for these program is no reason to do main + cpp + header

#define JUMP_CMD 0xe9

int MemProtect();
void MemChange();

void IHonestFirst()
{
	printf("You are beatiful\n");

	return;
}
void IHonestSecond()
{
	printf("You are terrrible\n");

	return;
}

int IHacker()
{	
	int luck = MemProtect();

	if (luck) MemChange();

	return luck;
}

int MemProtect()
{
	long long page_adress = ((long long)IHonestFirst | 4095) ^ 4095; // redoing 0x5421521542 to 0x5421521000 (for example)
	int err = mprotect((void*)page_adress, (size_t) getpagesize, PROT_READ | PROT_WRITE | PROT_EXEC);

	if (!err) printf("The hack failed. Memory is protected.\n");

	return err;
}

void MemChange()
{
	* (char*)IHonestFirst = JUMP_CMD;
	*((long*)((char*)IHonestFirst + 1)) = (long)(&IHonestSecond - &IHonestFirst - 5); // 5 because jump's argument is int number
}

void FuncThatCallIHonestFirst()
{
	printf("\nHello, I call IHonestFirst\n");
	IHonestFirst();
}

int main()
{
	IHonestFirst();
	FuncThatCallIHonestFirst();

	int end = IHacker();
	if (!end) return 404;

	IHonestFirst();
	IHonestFirst();
	IHonestSecond();

	FuncThatCallIHonestFirst();

	return 0;
}
