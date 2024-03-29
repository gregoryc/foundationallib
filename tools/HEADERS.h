
#ifndef _FOUNDATIONAL_LIB_HEADER_GUARD
#define _FOUNDATIONAL_LIB_HEADER_GUARD

#include <ctype.h>
#include <stdarg.h>
#include <stdio.h>
#ifdef _WIN32
#define _CRT_RAND_S
#endif
#include <stdlib.h>

#include <string.h>

#include <errno.h>

#ifndef FOUNDATIONAL_LIB_AGGRESSIVE_DIE_TYPE
/**
 * @brief Type of the aggressive die variable.
 *
 * This macro defines the type of the aggressive die variable, which
 * uses 1 byte of overhead by default. It can be configured as static
 * or nonstatic based on user preference.
 */
#define FOUNDATIONAL_LIB_AGGRESSIVE_DIE_TYPE static unsigned char
#endif

struct Dict;
struct FrozenDict;
struct Set;
struct FrozenSet;
char **list_files_with_pattern(const char *directory, const char *pattern, size_t *len);
char **read_file_into_array(const char *filename, const char *delim, size_t *num_lines);
char **sorted_char_ptrs(char **char_ptrs, size_t size);
char **sorted_strings(char **strings, size_t size);
char **split(const char *str, size_t *output_size, const char *delim, size_t max_times, int keep_delim_in_result);
char *backticks(const char *command, size_t *size);
char *concatenate_five_strings(const char *str1, const char *str2, const char *str3, const char *str4, const char *str5);
char *concatenate_four_strings(const char *str1, const char *str2, const char *str3, const char *str4);
char *concatenate_string_array(const char **strings, size_t num_strings);
char *concatenate_strings(const char *str1, const char *str2);
char *concatenate_three_strings(const char *str1, const char *str2, const char *str3);
char *dict_to_string(struct Dict *dict, int pointer_or_string) /* 0 = pointer, 1 = string */;
char *dup_format(const char *format, ...);
char *frozen_dict_to_string(struct FrozenDict *dict, int pointer_or_string) /* 0 = pointer, 1 = string */;
char *frozen_set_to_string(struct FrozenSet *frozen_set);
char *int_to_string(long long int number);
char *join(const char **array, size_t count, const char *delimiter);
char *longest_common_prefix(const char **strings, size_t count);
char *longest_common_suffix(const char **strings, size_t count);
char *read_file_into_string(const char *filename, size_t *size);
char *reduce_filesystem_files_as_strings(const char *directory, const char *out_file, char *(*reduce_function)(char *value1, ...));
char *replace_all(const char *source, const char *find, const char *replace);
char *replace_all_with_callback(const char *str, const char *old_substring, char *(*callback)(const char *, void *), void *data_for_callback);
char *replace_count(const char *source, const char *find, const char *replace, const size_t matches_max);
char *replace_first(const char *source, const char *find, const char *replace);
char *reverse_string(const char *str);
char *set_to_string(struct Set *set);
char *shellescape(const char *input);
char *sorted_chars(char *chars, size_t size);
char *string_to_json(const char *input_string);
char *string_to_lowercase(char *string);
char *string_to_title_case(const char *str);
char *string_to_uppercase(char *string);
char *strip(const char *str);
char *uint_to_string(size_t number);
const char *sample_strings(const char **strings, size_t size) /* Does not dynamically allocate memory. */;
double **sorted_double_ptrs(double **double_ptrs, size_t size);
double *sorted_doubles(double *doubles, size_t size);
double average_of_int_array(const int *array, size_t size);
float **sorted_float_ptrs(float **float_ptrs, size_t size);
float *sorted_floats(float *floats, size_t size);
int **sorted_int_ptrs(int **int_ptrs, size_t size);
int *sorted_ints(int *ints, size_t size);
int append_data_to_array(void **array, size_t *array_size, size_t *array_current_alloc_size, void *data, size_t data_size);
int append_data_to_array_no_initial_alloc(void **array, size_t *array_size, size_t *array_current_alloc_size, void *data, size_t data_size);
int append_string_to_array(char ***array, size_t *array_size, size_t *array_current_alloc_size, const char *string);
int append_string_to_array_no_initial_alloc(char ***array, size_t *array_size, size_t *array_current_alloc_size, const char *string);
int append_string_to_file(const char *filename, const char *content);
int append_string_to_string(char **string, size_t *string_length, size_t *string_alloc_size, const char *string_to_get_appended, size_t string_to_get_appended_length);
int copy_file(const char *source_filename, const char *destination_filename);
int dict_add(struct Dict *dict, const char *key, void *value);
int dict_reserve_more(struct Dict *dict, size_t number_of_new_elements_max_one_is_expecting);
int dict_resize(struct Dict *dict);
int dict_to_array(struct Dict *dict, char ***keys, void ***values, size_t *size_of_keys_and_values);
int download_website(const char *website, char **string, size_t *size, size_t *str_alloc_size, size_t byte_max_cutoff, const char *user_agent);
int download_websites(const char **websites_to_download, size_t num_websites, char ***outputs, size_t **lens, size_t byte_limit, int aggressive_stop_on_error);
int file_exists(const char *filename);
int file_is_directory(const char *filename);
int file_is_executable(const char *filename);
int file_is_readable(const char *filename);
int file_is_regular(const char *filename);
int file_is_writable(const char *filename);
int filter_filesystem_files_as_strings(const char *directory, int (*filter_function)(const char *filename));
int filter_ints(int *source, size_t source_size, int *destination, int (*condition)(int));
int find_max_int_in_array(const int *array, size_t size);
int find_min_int_in_array(const int *array, size_t size);
int frozen_set_in(struct FrozenSet *set, const char *key);
int frozen_set_to_array(struct FrozenSet *set, char ***keys, size_t *size_of_keys);
int get_file_size(const char *filename, size_t *size);
int ints_are_sorted_ascending(const int *array, size_t size);
int ints_are_sorted_descending(const int *array, size_t size);
int is_array_digit(const char **array, size_t size);
int is_array_lower(const char **array, size_t size);
int is_array_upper(const char **array, size_t size);
int is_string_alpha(const char *string);
int is_string_alphanumeric(const char *str);
int is_string_digit(const char *string);
int is_string_lower(const char *string);
int is_string_numeric(const char *str);
int is_string_printable(const char *string);
int is_string_space(const char *string);
int is_string_upper(const char *string);
int is_string_valid_integer(const char *str);
int is_valid_utf8(const char *str, size_t len);
int map_filesystem_files_as_strings(const char *directory, char *(*map_function)(const char *file_string_data, size_t string_size));
int memory_has_subchunk(void *memory, size_t memory_length, void *subchunk, size_t subchunk_length);
int prepend_string_to_array(char ***array, size_t *array_size, size_t *array_current_alloc_size, char *string);
int prepend_string_to_array_no_initial_alloc(char ***array, size_t *array_size, size_t *array_current_alloc_size, char *string);
int read_files_into_array(const char **files_to_open, size_t num_files, char ***outputs, size_t **lens, int aggressive_stop_on_error);
int reduce_ints(int *array, size_t size, int (*operation)(int, int));
int remove_file(const char *filename);
int replace_all_with_lens(const char *source, size_t source_len, const char *find, size_t find_len, const char *replace, size_t replace_len, char **output, size_t *new_len, int *should_free_after_use, size_t matches_max, size_t *num_matches);
int replace_memory(void *source, size_t source_len, void *find, size_t find_len, void *replace, size_t replace_len, void **output, size_t *output_length_without_nullt, int *should_free_after_use, size_t matches_max /* 0 for unlimited replacement */, size_t *num_matches_found, int should_nullt);
int set_add(struct Set *set, const char *key);
int set_in(struct Set *set, const char *key);
int set_reserve_more(struct Set *set, size_t number_of_new_elements_max_one_is_expecting);
int set_resize(struct Set *set);
int set_to_array(struct Set *set, char ***keys, size_t *size_of_keys);
int shuffle_strings_in_place(char **strings, size_t size);
int string_array_uniq(const char **array, size_t size, char ***output, size_t *output_size);
int string_array_uniq_adjacent(const char **first_array, size_t size, char ***new_array, size_t *new_size);
int string_has_substr(const char *string, size_t string_length, const char *substring, size_t substring_length);
int string_to_int(const char *str);
int sum_of_int_array(const int *array, size_t size);
int write_file(const char *filename, const char *content);
int write_to_file_with_mode(const char *filename, const char *content, size_t content_length, const char *mode);
long **sorted_long_ptrs(long **long_ptrs, size_t size);
long *sorted_longs(long *longs, size_t size);
long long **sorted_long_long_ptrs(long long **long_long_ptrs, size_t size);
long long *sorted_long_longs(long long *long_longs, size_t size);
long rand_number_from_range_inclusive_signed(signed long min, signed long max);
short **sorted_short_ptrs(short **short_ptrs, size_t size);
short *sorted_shorts(short *shorts, size_t size);
size_t **sorted_size_t_ptrs(size_t **size_t_ptrs, size_t size);
size_t *generate_range(size_t start, size_t end, size_t step, size_t *range_size);
size_t *sorted_size_ts(size_t *size_ts, size_t size);
size_t array_total_string_length(char **array, size_t count);
size_t common_prefix_length(const char *str1, const char *str2);
size_t common_suffix_length(const char *str1, const char *str2);
size_t count_occurrences_of_adjacent_data_in_array(const void *array_of_adjacent_values, size_t array_length, const void *memory, size_t memory_length);
size_t count_occurrences_of_data_in_array(const void **array_of_pointers, size_t array_length, const void *memory, size_t memory_length);
size_t count_occurrences_of_string_in_array(const char **array, const char *string, size_t array_length);
size_t count_occurrences_of_substr(const char *str, const char *substring);
size_t count_occurrences_of_substr_len(const char *string, size_t string_length, const char *substring, size_t substring_length);
size_t dict_hash(const char *key, size_t capacity);
size_t dict_size(struct Dict *dict);
size_t filter_data(void *source, size_t source_size, size_t elem_size, void *destination, size_t dest_size, int (*condition)(void *));
size_t frozen_dict_size(struct FrozenDict *dict);
size_t frozen_dict_to_array(struct FrozenDict *dict, char ***keys, void ***values, size_t *size_of_keys_and_values);
size_t frozen_set_size(struct FrozenSet *set);
size_t set_hash(const char *key, size_t capacity);
size_t set_size(struct Set *set);
ssize_t find_first_of(const char *str, const char *char_set);
ssize_t find_last_of(const char *str, const char *char_set);
struct Dict *dict_new_instance(void);
struct FrozenDict *frozen_dict_new_instance(size_t num_pairs, ...);
struct FrozenSet *frozen_set_new_instance(size_t num_args, ...);
struct Set *set_new_instance(void);
unsigned char **sorted_uchar_ptrs(unsigned char **uchar_ptrs, size_t size);
unsigned char *sorted_uchars(unsigned char *uchars, size_t size);
unsigned int **sorted_uint_ptrs(unsigned int **uint_ptrs, size_t size);
unsigned int *sorted_uints(unsigned int *uints, size_t size);
unsigned long **sorted_ulong_ptrs(unsigned long **ulong_ptrs, size_t size);
unsigned long *sorted_ulongs(unsigned long *ulongs, size_t size);
unsigned long long **sorted_ulong_long_ptrs(unsigned long long **ulong_long_ptrs, size_t size);
unsigned long long *sorted_ulong_longs(unsigned long long *ulong_longs, size_t size);
unsigned long rand_number_from_range_inclusive_unsigned(unsigned long min, unsigned long max);
unsigned short **sorted_ushort_ptrs(unsigned short **ushort_ptrs, size_t size);
unsigned short *sorted_ushorts(unsigned short *ushorts, size_t size);
void *arraydup(const void *array, size_t num_mem, size_t size);
void *dict_get(struct Dict *dict, const char *key);
void *dict_get_check(struct Dict *dict, const char *key, int *key_is_in_dict);
void *frozen_dict_get(struct FrozenDict *dict, const char *key);
void *frozen_dict_get_check(struct FrozenDict *dict, const char *key, int *key_is_in_dict);
void *list_comprehension(const void *input_array, size_t array_size, size_t elem_size, void (*transform_func)(void *value), int (*filter_func)(void *value), size_t *result_size);
void *list_comprehension_multithreaded(const void *input_array, size_t array_size, size_t elem_size, void (*transform_func)(void *value), int (*filter_func)(void *value), size_t *result_size, size_t thread_count);
void *memory_locate(const void *haystack, size_t haystack_len, const void *needle, size_t needle_len);
void *reject_array(const void *source, size_t source_size, size_t elem_size, int (*condition)(const void *), size_t *result_size);
void *replicate(const void *source, size_t source_size, size_t elem_size, size_t repetitions);
void *select_array(const void *source, size_t source_size, size_t elem_size, int (*condition)(const void *), size_t *result_size);
void dict_del_key(struct Dict *dict, const char *key);
void dict_destructor(struct Dict *dict);
void dict_iter(struct Dict *dict, void (*callback)(char *key, void *value));
void frozen_dict_destructor(struct FrozenDict *dict);
void frozen_dict_iter(struct FrozenDict *frozen_dict, void (*callback)(char *key, void *value));
void frozen_set_del_keys(char **keys);
void frozen_set_destructor(struct FrozenSet *frozen_set);
void frozen_set_iter(struct Set *set, void (*callback)(char *key));
void int_to_string_with_buffer(long long int number, char *buffer);
void map(void *array, size_t size, size_t elem_size, void (*transform)(void *));
void map_ints(int *array, size_t size, int (*transform)(int));
void print_char(const char value);
void print_char_array_to_stream(const char *array, size_t size, FILE *stream);
void print_char_to_stream(const char value, FILE *stream);
void print_double(const double value);
void print_double_array(const double *array, size_t size);
void print_double_array_to_stream(const double *array, size_t size, FILE *stream);
void print_double_ptr_array(const double **array, size_t size);
void print_double_ptr_array_to_stream(const double **array, size_t size, FILE *stream);
void print_double_to_stream(const double value, FILE *stream);
void print_float(const float value);
void print_float_array(const float *array, size_t size);
void print_float_array_to_stream(const float *array, size_t size, FILE *stream);
void print_float_ptr_array(const float **array, size_t size);
void print_float_ptr_array_to_stream(const float **array, size_t size, FILE *stream);
void print_float_to_stream(const float value, FILE *stream);
void print_int(const int value);
void print_int_array(const int *array, size_t size);
void print_int_array_to_stream(const int *array, size_t size, FILE *stream);
void print_int_ptr_array(const int **array, size_t size);
void print_int_ptr_array_to_stream(const int **array, size_t size, FILE *stream);
void print_int_to_stream(const int value, FILE *stream);
void print_long(const long value);
void print_long_array(const long *array, size_t size);
void print_long_array_to_stream(const long *array, size_t size, FILE *stream);
void print_long_long(const long long value);
void print_long_long_array(const long long *array, size_t size);
void print_long_long_array_to_stream(const long long *array, size_t size, FILE *stream);
void print_long_long_ptr_array(const long long **array, size_t size);
void print_long_long_ptr_array_to_stream(const long long **array, size_t size, FILE *stream);
void print_long_long_to_stream(const long long value, FILE *stream);
void print_long_ptr_array(const long **array, size_t size);
void print_long_ptr_array_to_stream(const long **array, size_t size, FILE *stream);
void print_long_to_stream(const long value, FILE *stream);
void print_short(const short value);
void print_short_array(const short *array, size_t size);
void print_short_array_to_stream(const short *array, size_t size, FILE *stream);
void print_short_ptr_array(const short **array, size_t size);
void print_short_ptr_array_to_stream(const short **array, size_t size, FILE *stream);
void print_short_to_stream(const short value, FILE *stream);
void print_size_t(const size_t value);
void print_size_t_array(const size_t *array, size_t size);
void print_size_t_array_to_stream(const size_t *array, size_t size, FILE *stream);
void print_size_t_ptr_array(const size_t **array, size_t size);
void print_size_t_ptr_array_to_stream(const size_t **array, size_t size, FILE *stream);
void print_size_t_to_stream(const size_t value, FILE *stream);
void print_string(char *value);
void print_string_array(char **array, size_t size);
void print_string_array_array(char ***array, size_t size);
void print_string_array_array_to_stream(char ***array, size_t size, FILE *stream);
void print_string_array_to_stream(char **array, size_t size, FILE *stream);
void print_string_to_stream(char *value, FILE *stream);
void print_uchar(const unsigned char value);
void print_uchar_array_to_stream(const unsigned char *array, size_t size, FILE *stream);
void print_uchar_to_stream(const unsigned char value, FILE *stream);
void print_uint(const unsigned int value);
void print_uint_array(const unsigned long long *array, size_t size);
void print_uint_array_to_stream(const unsigned int *array, size_t size, FILE *stream);
void print_uint_ptr_array(const unsigned int **array, size_t size);
void print_uint_ptr_array_to_stream(const unsigned int **array, size_t size, FILE *stream);
void print_uint_to_stream(const unsigned int value, FILE *stream);
void print_ulong(const unsigned long value);
void print_ulong_array(const unsigned long *array, size_t size);
void print_ulong_array_to_stream(const unsigned long *array, size_t size, FILE *stream);
void print_ulong_long(const unsigned long long value);
void print_ulong_long_array(const unsigned long long *array, size_t size);
void print_ulong_long_array_to_stream(const unsigned long long *array, size_t size, FILE *stream);
void print_ulong_long_ptr_array(const unsigned long long **array, size_t size);
void print_ulong_long_ptr_array_to_stream(const unsigned long long **array, size_t size, FILE *stream);
void print_ulong_long_to_stream(const unsigned long long value, FILE *stream);
void print_ulong_ptr_array(const unsigned long **array, size_t size);
void print_ulong_ptr_array_to_stream(const unsigned long **array, size_t size, FILE *stream);
void print_ulong_to_stream(const unsigned long value, FILE *stream);
void print_ushort(const unsigned short value);
void print_ushort_array(const unsigned short *array, size_t size);
void print_ushort_array_to_stream(const unsigned short *array, size_t size, FILE *stream);
void print_ushort_ptr_array(const unsigned short **array, size_t size);
void print_ushort_ptr_array_to_stream(const unsigned short **array, size_t size, FILE *stream);
void print_ushort_to_stream(const unsigned short value, FILE *stream);
void reduce(void *array, size_t size, size_t elem_size, void *result, void (*operation)(void *, void *));
void reverse_int_array_in_place(int *array, size_t size);
void reverse_string_in_place(char *str);
void set_del_key(struct Set *set, const char *key);
void set_del_keys(char **keys);
void set_destructor(struct Set *set);
void set_iter(struct Set *set, void (*callback)(char *key));
void sort_char_ptrs(char **char_ptrs, size_t size);
void sort_chars(char *chars, size_t size);
void sort_double_ptrs(double **double_ptrs, size_t size);
void sort_doubles(double *doubles, size_t size);
void sort_float_ptrs(float **float_ptrs, size_t size);
void sort_floats(float *floats, size_t size);
void sort_int_ptrs(int **int_ptrs, size_t size);
void sort_ints(int *ints, size_t size);
void sort_long_long_ptrs(long long **long_long_ptrs, size_t size);
void sort_long_longs(long long *long_longs, size_t size);
void sort_long_ptrs(long **long_ptrs, size_t size);
void sort_longs(long *longs, size_t size);
void sort_short_ptrs(short **short_ptrs, size_t size);
void sort_shorts(short *shorts, size_t size);
void sort_size_t_ptrs(size_t **size_t_ptrs, size_t size);
void sort_size_ts(size_t *size_ts, size_t size);
void sort_strings(char **strings, size_t size);
void sort_uchar_ptrs(unsigned char **uchar_ptrs, size_t size);
void sort_uchars(unsigned char *uchars, size_t size);
void sort_uint_ptrs(unsigned int **uint_ptrs, size_t size);
void sort_uints(unsigned int *uints, size_t size);
void sort_ulong_long_ptrs(unsigned long long **ulong_long_ptrs, size_t size);
void sort_ulong_longs(unsigned long long *ulong_longs, size_t size);
void sort_ulong_ptrs(unsigned long **ulong_ptrs, size_t size);
void sort_ulongs(unsigned long *ulongs, size_t size);
void sort_ushort_ptrs(unsigned short **ushort_ptrs, size_t size);
void sort_ushorts(unsigned short *ushorts, size_t size);
void utoa(size_t unsigned_value, char *output);
#endif