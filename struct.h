struct graphicsCard {
  int quantity;
  char * desc;
  char * onboard_memory;
  char * double_data_rate;
  char * expansion_bus;
  int year_of_manufacturer;
  double price;
};

struct monitorScreen {
  int quantity;
  char * desc;
  char * resolution;
  char * video_type;
  char * refresh_speed;
  double wattage;
  double price;
};

struct processorChip {
  int quantity;
  char * desc;
  double clock_speed;
  int cores;
  int threads;
  double price;
};
