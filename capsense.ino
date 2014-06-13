CapacitiveSensor sensorA = CapacitiveSensor(10,9);
CapacitiveSensor sensorB = CapacitiveSensor(10,11);

int getAValue() {
  return sensorA.capacitiveSensor(25)/64;
}

int getBValue() {
  return sensorB.capacitiveSensor(25)/64;
}