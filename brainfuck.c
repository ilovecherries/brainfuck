#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define MESSAGE "Brainfuck Interpreter\nWritten by Cherry\n-----\n"

int main(int argc, const char *argv[])
{	
	/* if (argc == 1) { */
	/* 	printf("%sInput the program as an argument.", MESSAGE); */
	/* 	return 0; */
	/* } else if (argc > 2){ */
	/* 	printf("%sToo many arguments.", MESSAGE); */
	/* 	return 1;		 */
	/* } */

	/* const char *program = argv[1]; */
	const char *program = "++[-]";

	int16_t memory[UINT16_MAX] = {0};
	uint16_t index = 0;

	uint32_t stack[UINT8_MAX] = {0};
	uint8_t stack_index = 0;

	uint32_t length = strlen(program);

	for (uint32_t i = 0; i < length; ++i) {
		switch (program[i]) {
		case '>': { // move pointer right
			++index; break;
		}
		case '<': { // move pointer left
			--index; break;
		}
		case '+': { // increase memory cell at pointer
			++memory[index]; break;
		}
		case '-': { // decrease memory cell at pointer
			--memory[index]; break;
		}
		case '.': { // output character at pointer
			printf("%c", memory[index]); break;
		}
		case ',': { // input character and store at pointer
			memory[index] = getchar(); break;
		}
		case '[': { // jump past matching brace if cell is 0
			if (memory[index] == 0) {
				uint8_t skip_index = stack_index + 1;
				uint8_t cur_index = skip_index;
				for (; cur_index >= skip_index; i++) {
					if (program[i] == '[') cur_index++;
					else if (program[i] == ']') cur_index--;
				}
			} else {
				stack[stack_index++] = i;
			}
			break;
		}
		case ']': { // jump to matching brace if cell is nonzero
			if (memory[index] != 0) {
				i = stack[stack_index - 1];
			} else {
				stack_index--;
			}
		}
		}
	}

	printf("\n");
    
    return 0;
}
