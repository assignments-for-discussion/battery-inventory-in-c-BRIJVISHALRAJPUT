#include <stdio.h>
#include <assert.h>

struct CountsByUsage {
  int lowCount;
  int mediumCount;
  int highCount;
};

struct CountsByUsage countBatteriesByUsage(const int* cycles, int nBatteries) {
  struct CountsByUsage counts = {0, 0, 0};
  int count1=0;
  int count2=0;
  int count3=0;
  for(int i=0;i<nBatteries;i++)
  {
  if(cycles[i]<400)
    count1++;
  else if(cycles[i]>=400&&cycles[i]<=919) 
    count2++;
  else if(cycles[i]>=920)
    count3++;
    
  }
  counts[0]=count1;
  counts[1]=count2;
  counts[3]=count3;
  return counts;
}

void testBucketingByNumberOfCycles() {
  const int chargeCycleCounts[] = {100, 300, 500, 600, 900, 1000};
  const int numberOfBatteries = sizeof(chargeCycleCounts) / sizeof(chargeCycleCounts[0]);
  printf("Counting batteries by usage cycles...\n");
  struct CountsByUsage counts = countBatteriesByUsage(chargeCycleCounts, numberOfBatteries);
  assert(counts.lowCount == 2);
  assert(counts.mediumCount == 3);
  assert(counts.highCount == 1);
  printf("Done counting :)\n");
}

int main() {
  testBucketingByNumberOfCycles();
  return 0;
}
