# C - File I/O

0. Tread lightly, she is near

Write a function that reads a text file and prints it to the POSIX standard output.

Prototype: ssize_t read_textfile(const char *filename, size_t letters);
where letters is the number of letters it should read and print
Returns the actual number of letters it could read and print

1. Under the snow
Create a function that creates a file.

Prototype: int create_file(const char *filename, char *text_content);
where filename is the name of the file to create and text_content is a NULL terminated string to write to the file
Returns: 1 on success, -1 on failure (file can not be created, file can not be written, write “fails”, etc…)

2. Speak gently, she can hear
Write a function that appends text at the end of a file.

Prototype: int append_text_to_file(const char *filename, char *text_content);
where filename is the name of the file and text_content is the NULL terminated string to add at the end of the file
Return: 1 on success and -1 on failure

3. cp
Write a program that copies the content of a file to another file.

4. elf
Write a program that displays the information contained in the ELF header at the start of an ELF file.
