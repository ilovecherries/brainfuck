#include <stdio.h>
#include <stdint.h>
#include <string.h>

int main(int argc, char *argv[])
{	
	int32_t memory[sizeof(uint32_t)] = {0};
	uint32_t index = 0;

	uint32_t stack[sizeof(uint8_t)] = {0};
	uint8_t stack_index = 0;

	char *program = "++++++++[>++++[>++>+++>+++>+<<<<-]>+>+>->>+[<]<-]>>.>---.+++++++..+++.>>.<-.<.+++.------.--------.>>+.>++.";
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
		case '-': { // increase memory cell at pointer
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
				i = stack[stack_index] + 1;
			}
		}
		}
	}

	printf("\n");
    
    return 0;
}
