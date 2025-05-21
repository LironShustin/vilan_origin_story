#pragma once
#ifndef FILE_READING_H
#define FILE_READING_H

void pull_line_from_file(const char* filename, int line_number, char* text_from_line, size_t text_from_line_size);
#endif
