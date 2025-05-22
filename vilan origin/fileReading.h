#pragma once
#ifndef FILE_READING_H
#define FILE_READING_H

void pull_line_from_file(const char* filename, int line_number, char* text_from_line, int text_from_line_size);

int write_lines_to_struct(const char* filename, int start_line, int N, Output_Vilain_Struct* data);
#endif
