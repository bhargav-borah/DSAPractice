string read(int n, vector<int> book, int target)
{
    sort(book.begin(), book.end());

    int left = 0;
    int right = book.size() - 1;

    while (left <= right) {
        if (book[left] + book[right] == target) return "YES";
        else if (book[left] + book[right] > target) right--;
        else if (book[left] + book[right] < target) left++;
    }

    return "NO";
}

