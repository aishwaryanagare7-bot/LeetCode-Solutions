char* convert(char* s, int numRows) {
    int n = strlen(s);

    if (numRows == 1 || numRows >= n)
        return s;

    char *ans = malloc(n + 1);
    int k = 0;
    int cycle = 2 * (numRows - 1);

    for (int row = 0; row < numRows; row++) {
        for (int i = row; i < n; i += cycle) {
            ans[k++] = s[i];

            if (row != 0 && row != numRows - 1) {
                int j = i + cycle - 2 * row;

                if (j < n)
                    ans[k++] = s[j];
            }
        }
    }

    ans[k] = '\0';
    return ans;
}