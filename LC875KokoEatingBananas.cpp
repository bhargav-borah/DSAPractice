int getMax(vector < int > & piles) {
  int maxi = INT_MIN;
  for (int i = 0; i < piles.size(); i++) {
    maxi = max(maxi, piles[i]);
  }

  return maxi;
}

long long getTimeTaken(vector < int > & piles, int speed) {
  long long timeTaken = 0;
  for (int i = 0; i < piles.size(); i++) {
    timeTaken += ceil((double) piles[i] / speed);
  }

  return timeTaken;
}

int minEatingSpeed(vector < int > & piles, int h) {
  int low = 1, high = getMax(piles);
  int res = -1;

  while (low <= high) {
    int mid = low + (high - low) / 2;
    long long timeTaken = getTimeTaken(piles, mid);
    if (timeTaken <= h) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }

  return low;
}

// int getMax(vector<int> arr) {
//     int maxi = INT_MIN;
//     for (int i = 0; i < arr.size(); i++) maxi = max(maxi, arr[i]);
    
//     return maxi;
// }

// int getTimeTaken(vector<int> piles, int speed) {
//     int timeTaken = 0;
//     for (int i = 0; i < piles.size(); i++) {
//         timeTaken += ceil((double)piles[i] / speed);
//     }
    
//     return timeTaken;
// }

// int minEatingSpeed(vector<int> piles, int h) {
//     int maxSpeed = getMax(piles) / 1;
    
//     for (int speed = 1; speed <= maxSpeed; speed++) {
//         int timeTaken = getTimeTaken(piles, speed);
//         if (timeTaken <= h) return speed;
//     }
    
//     return -1;
// }