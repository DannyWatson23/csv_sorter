#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "struct.h"

int graba(char *buff){
  FILE *f2;
  char write_file[20] = "data";
  char *sptr1, *token = NULL;
  if (strstr(buff, "Graphics")){
    struct graphicsCard *g1 = malloc(sizeof(g1) * 1024);
    g1->desc = malloc(sizeof(char)*1024);
    g1->onboard_memory = (char * )malloc(sizeof(char)*1024);
    g1->double_data_rate = (char *)malloc(sizeof(char)*1024);
    g1->expansion_bus = (char *)malloc(sizeof(char)*1024);
    token = strtok_r(buff, ",", &sptr1);
    g1->quantity = atoi(token);
    token = strtok_r(NULL, ",", &sptr1);
    strncpy(g1->desc, token, 68);
    token = strtok_r(NULL, ",", &sptr1);
    strcpy(g1->onboard_memory, token);
    token = strtok_r(NULL, ",", &sptr1);
    strcpy(g1->double_data_rate, token);
    token = strtok_r(NULL,",", &sptr1);
    strcpy(g1->expansion_bus, token);
    token = strtok_r(NULL,",", &sptr1);
    g1->year_of_manufacturer = atoi(token);
    token = strtok_r(NULL,",", &sptr1);
    g1->price = atoi(token);
    strcat(write_file, ".computers");
    f2 = fopen(write_file, "a+");
    fprintf(f2,"%i,%s,%s,%s,%s,%i,%.2f \n",g1->quantity,g1->desc,g1->onboard_memory,g1->double_data_rate,g1->expansion_bus,g1->year_of_manufacturer,g1->price);
    free(g1->expansion_bus);
    free(g1->double_data_rate);
    free(g1->onboard_memory);
    free(g1->desc);
    g1->expansion_bus = NULL;
    g1->double_data_rate = NULL;
    g1->onboard_memory = NULL;
    g1->desc = NULL;
    free(g1);
    printf("Freed graphics\n");
    g1 = NULL;
    fclose(f2);
    f2 = NULL;
  }
  else if (strstr(buff, "Monitor")){
    struct monitorScreen *s1 = malloc(sizeof(s1) * 1024);
    s1->desc = malloc(sizeof(char)*1024);
    s1->resolution = malloc(sizeof(char)*1024);
    s1->video_type = malloc(sizeof(char)*1024);
    s1->refresh_speed = malloc(sizeof(char)*1024);
    token = strtok_r(buff, ",", &sptr1);
    s1->quantity = atoi(token);
    token = strtok_r(NULL, ",", &sptr1);
    strncpy(s1->desc, token, 70);
    token = strtok_r(NULL, ",", &sptr1);
    strncpy(s1->resolution, token, 70);
    token = strtok_r(NULL, ",", &sptr1);
    strncpy(s1->video_type, token, 70);
    token = strtok_r(NULL, ",", &sptr1);
    strncpy(s1->refresh_speed, token, 70);
    token = strtok_r(NULL, ",", &sptr1);
    if (strstr(token, "W")){
       char mem_delim[] = "W";
       if (mem_delim == NULL)
        exit(1);
       char * token_mem = token;
       if (token_mem == NULL)
        exit(1);
       token = strtok_r(token_mem, mem_delim, &token_mem);
       sscanf(token, "%lf", &s1->wattage);
       token_mem = NULL;
     }
     token = strtok_r(NULL, ",", &sptr1);
     sscanf(token, "%lf", &s1->price);
     strcat(write_file, ".monitors");
     f2 = fopen(write_file, "a+");
     fprintf(f2,"%i,%s,%s,%s,%s,%.2f,%.2f \n",s1->quantity,s1->desc,s1->resolution,s1->video_type,s1->refresh_speed,s1->wattage,s1->price);
     free(s1->refresh_speed);
     free(s1->video_type);
     free(s1->resolution);
     free(s1->desc);
     s1->refresh_speed = NULL;
     s1->video_type = NULL;
     s1->resolution = NULL;
     s1->desc = NULL;
     free(s1);
     printf("Freed screen\n");
     s1 = NULL;
     fclose(f2);
     f2 = NULL;
  }
  else if (strstr(buff, "Processor")){
    struct processorChip *p1 = malloc(sizeof(p1)*1024);
    p1->desc = malloc(sizeof(char)*1024);
    token = strtok_r(buff, ",", &sptr1);
    p1->quantity = atoi(token);
    token = strtok_r(NULL, ",", &sptr1);
    strncpy(p1->desc, token, 70);
    token = strtok_r(NULL, ",", &sptr1);
    if ((strstr(token, "GHz") || strstr(token, "Ghz"))){
       char mem_delim[] = "G";
       if (mem_delim == NULL)
        exit(1);
       char * token_mem = token;
       if (token_mem == NULL)
        exit(1);
       token = strtok_r(token_mem, mem_delim, &token_mem);
       sscanf(token, "%lf", &p1->clock_speed);
       token_mem = NULL;
     }
    token = strtok_r(NULL, ",", &sptr1);
    p1->cores = atoi(token);
    token = strtok_r(NULL, ",", &sptr1);
    p1->threads = atoi(token);
    token = strtok_r(NULL, ",", &sptr1);
    sscanf(token, "%lf", &p1->price);
    strcat(write_file, ".processors");
    f2 = fopen(write_file, "a+");
    fprintf(f2,"%i,%s,%.2f,%i,%i,%.2f \n",p1->quantity,p1->desc,p1->clock_speed,p1->cores,p1->threads,p1->price);
    free(p1->desc);
    p1->desc = NULL;
    free(p1);
    printf("Freed processor\n");
    p1 = NULL;
    fclose(f2);
    f2 = NULL;
  }
}
