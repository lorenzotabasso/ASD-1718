package ex2;

/**
 * @author Lorenzo Tabasso, mat: 812499
 * @author Andrea Malgaoli, mat: 823429
 */

class EditDistance {

    /**
     * Support function used in EditDistance method.
     * It removes the first character of the given string.
     *
     * @param str: string to cut.
     *
     * @return the part of s without its first character.
     * @see #editDistance(String, String) for more information.
     */
    private static String rest(String str) {
        return str.length() > 1 ? str.substring(1) : "";
    }

    /**
     * Recursive method that computes the edit distance between the first string (str1) and the second string (str2).
     * More specifically, it finds the minimum number of deletion and insertion to transform
     * the second string in the first string.
     *
     * @param s1: First string.
     * @param s2: Second string.
     *
     * @return the edit distance between the two given strings (based only on insertion and deletion).
     */
    static int editDistance(String s1 , String s2) {

        // If |s1| = 0 then editDistance(s1,s2) = |s2|
        if (s1.length() == 0)
            return s2.length();

        // If |s2| = 0 then editDistance(s1,s2) = |s1|
        if (s2.length() == 0)
            return s1.length();

        int dNoop, dCanc, dIns;

        // Compute dNoop.
        if (s1.charAt(0) == s2.charAt(0))
            return editDistance(rest(s1), rest(s2));
        else
            dNoop = Integer.MAX_VALUE;

        // Compute dCanc and dIns.
        dCanc = 1 + editDistance(s1, rest(s2));
        dIns = 1 + editDistance(rest(s1), s2);

        // Find and return the minimum between dNoop, dCanc and dIns.
        return Math.min(Math.min(dNoop, dCanc), dIns);
    }

    /**
     * Iterative Bottom-up version of a Dynamic Programming method that computes the edit distance between
     * the first string (str1) and the second string (str2).
     * More specifically, it finds the minimum number of deletion and insertion to transform
     * the second string in the first string.
     *
     * @param str1: First string.
     * @param str2: Second string.
     *
     * @return the edit distance between the two given strings (based only on insertion and deletion).
     */
    static int editDistanceDynBottomUp(String str1, String str2) {
        int m = str1.length();
        int n = str2.length();

        int[][] editDistanceMatrix = new int[m + 1][n + 1]; // Create a matrix to store results of sub-problems

        // Filling d[][] in bottom up manner
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {

                // if |s1| = 0 then editDistance(s1,s2) = |s2|
                if (i == 0) {
                    editDistanceMatrix[i][j] = j; // Min. operations = j
                }

                // if |s2| = 0 then editDistance(s1,s2) = |s1|
                else if (j == 0) {
                    editDistanceMatrix[i][j] = i; // Min. operations = i
                }

                // Last characters are the same, ignore last character
                // and recur for remaining string
                else if (str1.charAt(i-1) == str2.charAt(j-1)) {
                    editDistanceMatrix[i][j] = editDistanceMatrix[i - 1][j - 1];
                }

                // Last characters are not same,
                // (1) compute dCanc and dIns
                // (2) find the minimum between dCanc and dIns
                // (3) store the minimum in dp[i][j].
                else {
                    int dCanc = 1 + editDistanceMatrix[i][j - 1]; // Remove operation
                    int dIns = 1 + editDistanceMatrix[i - 1][j]; // Insert operation
                    editDistanceMatrix[i][j] = Math.min(dCanc, dIns);
                }
            }
        }
        return editDistanceMatrix[m][n];
    }

    /**
     * Recursive Top-down version of a Dynamic Programming method that computes the edit distance between
     * the first string (str1) and the second string (str2).
     * More specifically, it finds the minimum number of deletion and insertion to transform
     * the second string in the first string.
     *
     * @param str1: First string.
     * @param str2: Second string.
     *
     * @return the edit distance between the two given strings (based only on insertion and deletion).
     */
    static int editDistanceDynTopDown(String str1, String str2) {

        // Initializing the matrix for the algorithm
        int[][] dp = new int[str1.length() + 1][str2.length() + 1];

        // filling the matrix cells with -1 (except for last row and last column)
        for (int i = 0; i < str1.length(); i++) {
            for (int j = 0; j < str2.length(); j++) {
                dp[i][j] = -1;
            }
        }

        return editDistDynRec(str1, str2, str1.length(), str2.length(), dp);
    }

    /**
     * Recursive method called in editDistanceDynTopDown, computes the edit distance between
     * the first string (str1) and the second string (str2).
     * More specifically, it finds the minimum number of deletion and insertion to transform
     * the second string in the first string.
     *
     * @param str1: First string.
     * @param str2: Second string.
     * @param m: length of first string (str1)
     * @param n: length of second string (str2)
     * @param dp: a integer matrix in which store the result of all the recursive calls
     *
     * @return the edit distance between the two given strings (based only on insertion and deletion).
     * @see #editDistanceDynTopDown(String, String) for more information.
     */
    private static int editDistDynRec(String str1, String str2, int m, int n, int[][] dp) {

        // If |s1| = 0 then editDistance(s1,s2) = |s2|
        if (m == 0) {
            return n;
        }

        // If |s2| = 0 then editDistance(s1,s2) = |s1|
        else if (n == 0) {
            return m;
        }

        // If the recursive call has been called previously, return
        // Its stored value memorized in the matrix
        else if (dp[m - 1][n - 1] != -1) {
            return dp[m - 1][n - 1];
        }

        // Last characters are the same,
        // ignore last characters and get count for remaining strings.
        // Store the returned value at dp[m-1][n-1]
        else if (str1.charAt(m - 1) == str2.charAt(n - 1)) {
            return dp[m - 1][n - 1] = editDistDynRec(str1, str2, m - 1, n - 1, dp);
        }

        // If last characters are not same,
        // (1) compute dCanc and dIns
        // (2) find the minimum between dCanc and dIns
        // (3) store the minimum in dp[m-1][n-1].
        else {
            int dCanc = editDistDynRec(str1, str2, m - 1, n, dp); // Remove
            int dIns = editDistDynRec(str1, str2, m, n - 1, dp); // Insert
            return dp[m - 1][n - 1] = 1 + Math.min(dIns, dCanc);
        }
    }
}

