#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

// определяем структуру для записи, как строках
struct Record {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
    int status;
    int code;
};
void start_menu();

void print_file(char *filename);
int sort_file(char *filename);
void add_record(char *filename);

int get_records_count_in_file(FILE *file);
void write_record_in_end(char *filename, struct Record *rec);

int mergeFiles(char *filename, int number_of_parts);
void merge(struct Record arr[], int l, int m, int r);

int main() {
    start_menu();
    return 0;
}

void start_menu() {
    int selected;
    char filename[100];
    if (scanf("%s", filename) == 1) {
        if (scanf("%d", &selected) != 0) {
            switch (selected) {
                case 0:
                    print_file(filename);
                    break;
                case 1:
                    sort_file(filename);
                    print_file(filename);
                    break;
                case 2: {
                    add_record(filename);
                    // print_file(filename);
                    break;
                }
                default:
                    printf("n/a\n");
                    break;
            }
        } else {
            printf("n/a\n");
        }
    } else {
        printf("n/a");
    }
}

void add_record(char *filename) {
    struct Record *rec;
    rec = malloc(sizeof(struct Record));
    if (scanf("%d %d %d %d %d %d %d %d", &rec->year, &rec->month, &rec->day, &rec->hour, &rec->minute,
              &rec->second, &rec->status, &rec->code) != 8) {
        printf("n/a");
    } else {
        FILE *file;
        file = fopen(filename, "r");
        int count = get_records_count_in_file(file);
        printf("%d\n", count);
        fclose(file);

        write_record_in_end(filename, rec);
        sort_file(filename);
        // print_file(filename);

        file = fopen(filename, "r");
        count = get_records_count_in_file(file);
        printf("%d\n", count);
        fclose(file);
    }
    free(rec);
}

void print_file(char *filename) {
    FILE *file;
    struct Record rec;
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("n/a");
    } else {
        while (fread(&rec, sizeof(rec), 1, file) == 1) {
            printf("%d %d %d %d %d %d %d %d\n", rec.year, rec.month, rec.day, rec.hour, rec.minute,
                   rec.second, rec.status, rec.code);
        }
    }
    fclose(file);
}

// ANOTHER FILE 11111111

// функция слияния двух отсортированных подмассивов arr[l..m] и arr[m+1..r]
void merge(struct Record arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    // создаем временные массивы
    struct Record L[n1], R[n2];
    // копируем данные во временные массивы
    for (i = 0; i < n1; i++) L[i] = arr[l + i];
    for (j = 0; j < n2; j++) R[j] = arr[m + 1 + j];
    // сливаем временные массивы обратно в arr[l..r]
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i].year < R[j].year || (L[i].year == R[j].year && L[i].month < R[j].month) ||
            (L[i].year == R[j].year && L[i].month == R[j].month && L[i].day < R[j].day) ||
            (L[i].year == R[j].year && L[i].month == R[j].month && L[i].day == R[j].day &&
             L[i].hour < R[j].hour) ||
            (L[i].year == R[j].year && L[i].month == R[j].month && L[i].day == R[j].day &&
             L[i].hour == R[j].hour && L[i].minute < R[j].minute) ||
            (L[i].year == R[j].year && L[i].month == R[j].month && L[i].day == R[j].day &&
             L[i].hour == R[j].hour && L[i].minute == R[j].minute && L[i].second < R[j].second)) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    // копируем оставшиеся элементы из L, если они остались
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    // копируем оставшиеся элементы из R, если они остались
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// функция сортировки слиянием
void mergeSort(struct Record arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// функция, которая делит файл на number_of_parts частей и записывает их в отдельные файлы под временными
// именами
int splitFile(char *filename, int number_of_parts) {
    FILE *in_file = fopen(filename, "rb");
    if (!in_file) {
        printf("Can't open input file %s\n", filename);
        return 0;
    }

    // определяем размер файла
    fseek(in_file, 0, SEEK_END);
    long file_size = ftell(in_file);
    rewind(in_file);
    // определяем размер одной части
    long part_size = (file_size / number_of_parts);
    struct Record record;
    int records_per_part = part_size / sizeof(record);

    for (int i = 0; i < number_of_parts; i++) {
        char *temp_file_name = malloc(sizeof(char) * 20);
        sprintf(temp_file_name, "temp%02d.bin", i);

        FILE *out_file = fopen(temp_file_name, "wb");
        if (!out_file) {
            printf("n/a");
            return 0;
        }

        for (int j = 0; j < records_per_part; j++) {
            if (!fread(&record, sizeof(record), 1, in_file)) break;
            fwrite(&record, sizeof(record), 1, out_file);
        }
        fclose(out_file);
        free(temp_file_name);
    }

    fclose(in_file);
    return 1;
}

// функция объединения файлов в один отсортированный файл
int mergeFiles(char *filename, int number_of_parts) {
    // создаем массив из number_of_parts указателей на файлы
    FILE **files = malloc(sizeof(FILE *) * number_of_parts);
    if (!files) {
        printf("n/a");
        return 0;
    }
    for (int i = 0; i < number_of_parts; i++) {
        char *temp_file_name = malloc(sizeof(char) * 20);
        sprintf(temp_file_name, "temp%02d.bin", i);

        files[i] = fopen(temp_file_name, "rb");
        if (!files[i]) {
            printf("n/a");
            return 0;
        }
        free(temp_file_name);
    }

    FILE *out_file = fopen(filename, "wb");
    if (!out_file) {
        printf("n/a");
        return 0;
    }

    // создаем массив из number_of_parts записей
    struct Record *records = malloc(sizeof(struct Record) * number_of_parts);
    if (!records) {
        printf("n/a");
        return 0;
    }

    int *indexes = malloc(sizeof(int) * number_of_parts);
    if (!indexes) {
        printf("n/a");
        return 0;
    }

    // читаем первую запись из каждого файла
    for (int i = 0; i < number_of_parts; i++) {
        if (fread(&records[i], sizeof(struct Record), 1, files[i]) == 1) {
            indexes[i] = i;
        } else {
            indexes[i] = -1;  // файл пуст
        }
    }

    while (1) {
        int min_index = -1;

        // находим номер файла с минимальной записью
        for (int i = 0; i < number_of_parts; i++) {
            if (indexes[i] != -1 &&
                (min_index == -1 || records[i].year < records[min_index].year ||
                 (records[i].year == records[min_index].year &&
                  records[i].month < records[min_index].month) ||
                 (records[i].year == records[min_index].year &&
                  records[i].month == records[min_index].month && records[i].day < records[min_index].day) ||
                 (records[i].year == records[min_index].year &&
                  records[i].month == records[min_index].month && records[i].day == records[min_index].day &&
                  records[i].hour < records[min_index].hour) ||
                 (records[i].year == records[min_index].year &&
                  records[i].month == records[min_index].month && records[i].day == records[min_index].day &&
                  records[i].hour == records[min_index].hour &&
                  records[i].minute < records[min_index].minute) ||
                 (records[i].year == records[min_index].year &&
                  records[i].month == records[min_index].month && records[i].day == records[min_index].day &&
                  records[i].hour == records[min_index].hour &&
                  records[i].minute == records[min_index].minute &&
                  records[i].second < records[min_index].second))) {
                min_index = i;
            }
        }

        // если все файлы были прочитаны, выходим из цикла
        if (min_index == -1) break;

        // записываем минимальную запись в выходной файл
        fwrite(&records[min_index], sizeof(struct Record), 1, out_file);

        // читаем следующую запись из файла, записываем в records и обновляем индекс
        if (fread(&records[min_index], sizeof(struct Record), 1, files[min_index]) == 1) {
            indexes[min_index] = min_index;
        } else {
            indexes[min_index] = -1;  // файл пуст
        }
    }

    fclose(out_file);
    for (int i = 0; i < number_of_parts; i++) {
        fclose(files[i]);
    }
    free(files);
    free(records);
    free(indexes);

    return 1;
}

int sort_file(char *filename) {
    int number_of_parts = 4;  // количество частей в которые мы разделим файл

    // пытаемся разбить файл на части
    if (splitFile(filename, number_of_parts) == 0) {
        printf("n/a");
        return 1;
    }

    // сортируем каждый файл-часть отдельно
    for (int i = 0; i < number_of_parts; i++) {
        char *temp_file_name = malloc(sizeof(char) * 20);
        sprintf(temp_file_name, "temp%02d.bin", i);
        FILE *file = fopen(temp_file_name, "rb");
        if (!file) {
            printf("n/a");
            return 1;
        }
        int num_records;
        fseek(file, 0, SEEK_END);
        num_records = ftell(file) / sizeof(struct Record);
        rewind(file);

        struct Record *records = malloc(sizeof(struct Record) * num_records);
        if (!records) {
            printf("n/a");
            return 1;
        }

        if (!fread(records, sizeof(struct Record), num_records, file)) {
            printf("n/a");
            return 1;
        }
        fclose(file);

        mergeSort(records, 0, num_records - 1);

        FILE *out_file = fopen(temp_file_name, "wb");
        if (!out_file) {
            printf("n/a");
            return 1;
        }

        if (!fwrite(records, sizeof(struct Record), num_records, out_file)) {
            printf("n/a");
            return 1;
        }
        fclose(out_file);

        free(records);
        free(temp_file_name);
    }

    // пытаемся объединить файл-части
    if (mergeFiles(filename, number_of_parts) == 0) {
        printf("Can't merge files\n");
        return 1;
    }

    //Удаляем файлы
    for (int i = 0; i < number_of_parts; i++) {
        char *temp_file_name = malloc(sizeof(char) * 20);
        sprintf(temp_file_name, "temp%02d.bin", i);
        remove(temp_file_name);
    }
    return 0;
}

void write_record_in_end(char *filename, struct Record *record_to_write) {
    FILE *pfile = fopen(filename, "ab");
    fwrite(record_to_write, sizeof(struct Record), 1, pfile);
    fclose(pfile);
}

// Function to get file size in bytes.
int get_file_size_in_bytes(FILE *pfile) {
    int size = 0;
    fseek(pfile, 0, SEEK_END);  // Move the position pointer to the end of the file.
    size = ftell(
        pfile);  // Read the number of bytes from the beginning of the file to the current position pointer.
    rewind(pfile);  // For safety reasons, move the position pointer back to the beginning of the file.
    return size;
}

// Function to get count of records in file
int get_records_count_in_file(FILE *pfile) { return get_file_size_in_bytes(pfile) / sizeof(struct Record); }
