#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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

// функция для преобразования строки с датой в структуру tm
int parseDate(const char *dateStr, struct tm *date) {
    memset(date, 0, sizeof(struct tm));
    char *result = strptime(dateStr, "%d.%m.%Y", date);
    if (!result || *result != '\0') return 0;
    return 1;
}

// функция, которая ищет первую запись с указанной датой и возвращает код или -1, если ничего не найдено
int findCodeByDate(const char *filename, const char *dateStr) {
    int flag = 0;
    FILE *file = fopen(filename, "rb");
    struct Record record;
    struct tm date;
    if (!parseDate(dateStr, &date)) {
        printf("n/a");
    } else {
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
                fclose(file);
                printf("n/a");
                flag = 0;
            } else {
                if (difftime(recordTime, mktime(&date)) >= 0) {
                    int code = record.code;
                    fclose(file);
                    flag = code;
                }
            }
        }
    }
    fclose(file);
    return flag;
}

int main() {
    char filename[100];
    char dateStr[11];
    if (scanf("%s", filename) == 1) {
        FILE *file = fopen(filename, "rb");
        if (!file) {
            printf("n/a");
        } else {
            fclose(file);
            if (scanf("%s", dateStr) == 1) {
                int code = findCodeByDate(filename, dateStr);
                if (code > 0) {
                    printf("%d", code);
                }
                if (code == 0) {
                    printf("n/a");
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