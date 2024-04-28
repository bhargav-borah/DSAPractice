int countPartitions(vector<int>& boards, int maxSum) {
    int partitions = 1;
    int sum = 0;

    for (int i = 0; i < boards.size(); i++) {
        if (sum + boards[i] <= maxSum) {
            sum += boards[i];
        }
        else {
            partitions++;
            sum = boards[i];
        }
    }

    return partitions;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    int low = *max_element(boards.begin(), boards.end());
    int high = accumulate(boards.begin(), boards.end(), 0);

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (countPartitions(boards, mid) > k) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return low;
}