#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "fileSaving.h"
#include "questions.h"
#include "editingFiles.h"

int main() {
	char answers_file[260];
	bool realistic = true;
	create_answers_file(answers_file);
	genre(realistic, answers_file);
	how_long_you_met(answers_file);
	return 0;
}