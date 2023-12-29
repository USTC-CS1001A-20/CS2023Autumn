#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX_SIZE 100000
#if 1

typedef struct WordNode {
    char* word;
    int position;
    struct WordNode* next;
} WordNode;

WordNode* createNode(char* word, int position) {
    WordNode* newNode = (WordNode*)malloc(sizeof(WordNode));
    newNode->word = word;
    newNode->position = position;
    newNode->next = NULL;
    return newNode;
}

void appendNode(WordNode** head, WordNode* newNode) {
    if (*head == NULL) {
        *head = newNode;
    }
    else {
        WordNode* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void freeList(WordNode* head) {
    WordNode* current = head;
    while (current != NULL) {
        WordNode* temp = current;
        current = current->next;
        free(temp);
    }
}

unsigned long hash(char* str) {
    unsigned long hash = 5381;
    int c;

    while (c = *str++) {
        hash = ((hash << 5) + hash) + c;
    }

    return hash;
}

double calculateCosineSimilarity(int* vector1, int* vector2, int size) {
    double dotProduct = 0.0;
    double magnitude1 = 0.0;
    double magnitude2 = 0.0;

    for (int i = 0; i < size; i++) {
        dotProduct += vector1[i] * vector2[i];
        magnitude1 += vector1[i] * vector1[i];
        magnitude2 += vector2[i] * vector2[i];
    }

    magnitude1 = sqrt(magnitude1);
    magnitude2 = sqrt(magnitude2);

    if (magnitude1 == 0 || magnitude2 == 0)
        return 0.0;

    return dotProduct / (magnitude1 * magnitude2);
}

void tokenizeText(char* text, char** tokens, int* tokenCount) {
    char* token = strtok(text, " ");
    while (token != NULL) {
        tokens[*tokenCount] = token;
        (*tokenCount)++;
        token = strtok(NULL, " ");
    }
}

void buildFeatureVector(char** tokens, int* vector, int tokenCount) {
    for (int i = 0; i < tokenCount; i++) {
        unsigned long hashValue = hash(tokens[i]);
        int index = hashValue % tokenCount;
        vector[index]++;
    }
}

void markDuplicate(char* text1, char* text2, char* markedText1, char* markedText2, int* vector1, int* vector2, int size, WordNode** duplicateList) {
    char* token1 = strtok(text1, " ");
    char* token2 = strtok(text2, " ");
    int index = 0;
    int position = 0;

    while (token1 != NULL && token2 != NULL) {
        if (vector1[index] > 0 && vector2[index] > 0) {
            WordNode* newNode = createNode(token1, position);
            appendNode(duplicateList, newNode);

            strcat(markedText1, "<span class='duplicate'>");
            strcat(markedText1, token1);
            strcat(markedText1, "</span> ");

            strcat(markedText2, "<span class='duplicate'>");
            strcat(markedText2, token2);
            strcat(markedText2, "</span> ");
        }
        else {
            strcat(markedText1, token1);
            strcat(markedText1, " ");

            strcat(markedText2, token2);
            strcat(markedText2, " ");
        }

        token1 = strtok(NULL, " ");
        token2 = strtok(NULL, " ");
        index++;
        position++;
    }

    while (token1 != NULL) {
        strcat(markedText1, token1);
        strcat(markedText1, " ");
        token1 = strtok(NULL, " ");
        position++;
    }

    while (token2 != NULL) {
        strcat(markedText2, token2);
        strcat(markedText2, " ");
        token2 = strtok(NULL, " ");
        position++;
    }
}

void printDuplicateList(WordNode* duplicateList) {
    printf("重复单词及其位置：\n");
    WordNode* current = duplicateList;
    while (current != NULL) {
        printf("%s\t位置：%d\n", current->word, current->position);
        current = current->next;
    }
}

void generateReport(char* filename1, char* filename2, double similarity, char* markedText1, char* markedText2, WordNode* duplicateList) {
    FILE* report = fopen("report.html", "w");
    if (report == NULL) {
        printf("无法创建查重报告文件。\n");
        return;
    }

    fprintf(report, "<html>\n");
    fprintf(report, "<head>\n");
    
    fprintf(report, "<title>查重报告</title>\n");
    
    fprintf(report, "<style>\n");
    fprintf(report, "body { font-family: Arial; }\n");
    fprintf(report, ".title { font-size: 24px; font-weight: bold; margin-bottom: 30px; }\n");
    fprintf(report, ".subtitle { font-size: 18px; font-weight: bold; margin-top: 30px; margin-bottom: 10px; }\n");
    fprintf(report, ".text { margin-bottom: 20px; }\n");
    fprintf(report, ".duplicate { color: red; }\n");
    fprintf(report, "</style>\n");
    
    fprintf(report, "</head>\n");
    fprintf(report, "<body>\n");
    fprintf(report, "<div class='title'>查重报告</div>\n");
    fprintf(report, "<div class='subtitle'>文件一：</div>\n");
    fprintf(report, "<div class='text'>%s</div>\n", markedText1);
    fprintf(report, "<div class='subtitle'>文件二：</div>\n");
    fprintf(report, "<div class='text'>%s</div>\n", markedText2);
    fprintf(report, "<div class='subtitle'>相似度分数：</div>\n");
    fprintf(report, "<div class='text'>%.2f%%</div>\n", similarity * 100);
    fprintf(report, "<div class='subtitle'>重复单词及其位置：</div>\n");
    fprintf(report, "<div class='text'>\n");
    
    WordNode* current = duplicateList;
    while (current != NULL) {
        fprintf(report, "%s\t位置：%d<br>\n", current->word, current->position);
        current = current->next;
    }
    fprintf(report, "</div>\n");
    fprintf(report, "</body>\n");
    fprintf(report, "</html>\n");
    time_t currentTime;
    struct tm* localTime;
    time(&currentTime);
    localTime = localtime(&currentTime);

    fprintf(report, "<div class='subtitle'>生成时间：</div>\n");
    fprintf(report, "<div class='text'>%s</div>\n", asctime(localTime)); // 打印系统时间

    fprintf(report, "</body>\n");
    fprintf(report, "</html>\n");
    printf("查重报告已生成，文件名为 report.html。\n");

    fclose(report);
}

void runInteractiveMode() {
    char filename1[256];
    char filename2[256];
    printf("请输入第一个文件名：\n");
    scanf("%s", filename1);
    printf("请输入第二个文件名：\n");
    scanf("%s", filename2);

    FILE* file1 = fopen(filename1, "r");
    FILE* file2 = fopen(filename2, "r");

    if (file1 == NULL || file2 == NULL) {
        printf("无法打开文件，请检查文件名是否正确。\n");
        return;
    }

    char* text1 = (char*)malloc(sizeof(char) * MAX_SIZE);
    char* text2 = (char*)malloc(sizeof(char) * MAX_SIZE);

    fgets(text1, MAX_SIZE, file1);
    fgets(text2, MAX_SIZE, file2);

    fclose(file1);
    fclose(file2);

    int tokenCount1 = 0;
    int tokenCount2 = 0;

    char** tokens1 = (char**)malloc(sizeof(char*) * MAX_SIZE);
    char** tokens2 = (char**)malloc(sizeof(char*) * MAX_SIZE);

    tokenizeText(text1, tokens1, &tokenCount1);
    tokenizeText(text2, tokens2, &tokenCount2);

    int* vector1 = (int*)calloc(tokenCount1, sizeof(int));
    int* vector2 = (int*)calloc(tokenCount2, sizeof(int));

    buildFeatureVector(tokens1, vector1, tokenCount1);
    buildFeatureVector(tokens2, vector2, tokenCount2);

    double similarity = calculateCosineSimilarity(vector1, vector2, fmin(tokenCount1, tokenCount2));

    char* markedText1 = (char*)malloc(sizeof(char) * MAX_SIZE);
    char* markedText2 = (char*)malloc(sizeof(char) * MAX_SIZE);
    WordNode* duplicateList = NULL;

    memset(markedText1, 0, sizeof(char) * MAX_SIZE);
    memset(markedText2, 0, sizeof(char) * MAX_SIZE);

    markDuplicate(text1, text2, markedText1, markedText2, vector1, vector2, fmin(tokenCount1, tokenCount2), &duplicateList);

    generateReport(filename1, filename2, similarity, markedText1, markedText2, duplicateList);

    free(text1);
    free(text2);
    free(tokens1);
    free(tokens2);
    free(vector1);
    free(vector2);
    free(markedText1);
    free(markedText2);
    freeList(duplicateList);
}

int main() {
    runInteractiveMode();
    return 0;
}

#endif