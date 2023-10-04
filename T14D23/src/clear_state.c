#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

// определяем структуру для записи, как в вашем примере
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

void print_file(char *filename) {
    FILE *file;
    struct Record rec;
    file = fopen(filename, "rb");
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

// функция для преобразования строки с датой в структуру tm
int parseDate(const char *dateStr, struct tm *date) {
    memset(date, 0, sizeof(struct tm));
    char *result = strptime(dateStr, "%d.%m.%Y", date);
    if (!result || *result != '\0') return 0;
    return 1;
}

// функция, которая удаляет записи, попадающие в указанный временной промежуток, из файла
int removeRecordsByDate(const char *filename, const char *startDateStr, const char *endDateStr) {
    int flag = 0;
    FILE *file = fopen(filename, "rb+");
    if (!file) {
        // printf("Can't open input file %s\n", filename);
        flag = -1;
    }

    struct Record record;
    struct tm startDate, endDate;
    if (!parseDate(startDateStr, &startDate)) {
        // printf("Invalid start date format: %s\n", startDateStr);
        fclose(file);
        flag = -1;
    }
    if (!parseDate(endDateStr, &endDate)) {
        // printf("Invalid end date format: %s\n", endDateStr);
        fclose(file);
        flag = -1;
    }

    int numRecordsToRemove = 0;
    long readPosition = ftell(file);
    long writePosition = readPosition;

    time_t startTime = mktime(&startDate);
    time_t endTime = mktime(&endDate);
    while (fread(&record, sizeof(struct Record), 1, file)) {
        struct tm recordDate = {.tm_year = record.year - 1900,
                                .tm_mon = record.month - 1,
                                .tm_mday = record.day,
                                .tm_hour = record.hour,
                                .tm_min = record.minute,
                                .tm_sec = record.second,
                                .tm_isdst = -1};
        time_t recordTime = mktime(&recordDate);
        if (recordTime == -1) {
            // printf("Can't convert record date\n");
            fclose(file);
            flag = -1;
        }
        
        if (difftime(recordTime, startTime) >= 0 && difftime(endTime, recordTime) >= 0) {
            numRecordsToRemove++;
        } else {
            if (readPosition != writePosition) {
                fseek(file, writePosition, SEEK_SET);
                fwrite(&record, sizeof(struct Record), 1, file);
                fseek(file, readPosition, SEEK_SET);
            }
            writePosition += sizeof(struct Record);
        }
        readPosition += sizeof(struct Record);
    }

    if (ftruncate(fileno(file), ftell(file) - numRecordsToRemove * sizeof(struct Record)) != 0) {
        // printf("Can't truncate file\n");
        fclose(file);
        flag = -1;
    }

    fclose(file);
    return flag;
}

int main() {
    // char *startDateStr = "01.01.2022";  // начальная дата
    // char *endDateStr = "31.12.2022";    // конечная дата
    char filename[100];
    char startDateStr[11];
    char endDateStr[11];

    if (scanf("%s", filename) == 1) {
        FILE *file = fopen(filename, "rb");
        if (!file) {
            printf("n/a");
        } else {
            fclose(file);
            if (scanf("%s %s", startDateStr, endDateStr) == 2) {
                if (removeRecordsByDate(filename, startDateStr, endDateStr) != 0) {
                    printf("n/a");
                } else {
                    print_file(filename);
                }
            } else {
                printf("n/a\n");
            }
        }
    } else {
        printf("n/a\n");
    }
    return 0;
}