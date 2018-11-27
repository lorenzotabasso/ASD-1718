package ex2;

/**
 * @author Lorenzo Tabasso, mat: 812499
 * @author Andrea Malgaoli, mat: 823429
 */

public class EditDistance {

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
        return str.length() > 1 ? str.substring(1) : null;
    }

    /**
     * It computes the edit distance between fthe first string (str1) and the second string (str2),
     * in other words the minimum number of deletion and insertion to transform
     * the second string in the first string.
     *
     * @param str1: First string.
     * @param str2: Second string.
     *
     * @return the edit distance between the two given strings (based only on insertion and deletion).
     */
    public static int editDistance(String str1, String str2) {
        if (str1 == null && str2 == null)
            return 0;
        else if (str1 == null && str2 != null)
            return 1 + editDistance(str1, rest(str2)); // canc
        else if (str1 != null && str2 == null)
            return 1 + editDistance(rest(str1), str2);    // ins
        else if (str1.charAt(0) == str2.charAt(0))
            return editDistance(rest(str1), rest(str2)); // no-op
        else {
            if ((str2.length() > 1) && (str1.charAt(0) == str2.charAt(1)))
                return 1 + editDistance(str1, rest(str2)); // canc
            else
                return 2 + editDistance(rest(str1), rest(str2)); // 1 canc + 1 ins
        }
    }

    /**
     * Iterative Bottom-up version of a Dynamic Programming method that computes the edit distance between
     * the first string (str1) and the second string (str2), in other words
     * the minimum number of deletion and insertion to transform
     * the second string in the first string.
     *
     * @param str1: First string.
     * @param str2: Second string.
     *
     * @return the edit distance between the two given strings (based only on insertion and deletion).
     */
    public static int editDistanceDynBottomUp(String str1, String str2) {
        int m = str1.length();
        int n = str2.length();

        // Create a table to store results of subproblems
        int dp[][] = new int[m+1][n+1];

        // Fill d[][] in bottom up manner
        for (int i=0; i<=m; i++) {
            for (int j=0; j<=n; j++) {
                // If first string is empty, only option is to
                // isnert all characters of second string
                if (i==0) {
                    dp[i][j] = j; // Min. operations = j
                }
                    // If second string is empty, only option is to
                    // remove all characters of second string
                else if (j==0) {
                    dp[i][j] = i; // Min. operations = i
                }
                    // If last characters are same, ignore last char
                    // and recur for remaining string
                else if (str1.charAt(i-1) == str2.charAt(j-1)) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                    // If the last character is different, consider all
                    // possibilities and find the minimum
                else {
                    int dcanc = 1 + dp[i][j - 1]; // Remove
                    int dins = 1 + dp[i - 1][j]; // Insert
                    dp[i][j] = Math.min(dcanc, dins);
                }
            }
        }

        return dp[m][n];
    }

    /**
     * Recursive Top-down version of a Dynamic Programming method that computes the edit distance between
     * the first string (str1) and the second string (str2), in other words
     * the minimum number of deletion and insertion to transform
     * the second string in the first string.
     *
     * @param str1: First string.
     * @param str2: Second string.
     *
     * @return the edit distance between the two given strings (based only on insertion and deletion).
     */
    public static int editDistanceDynTopDown(String str1, String str2) {
        int[][] dp = new int[str1.length() + 1][str2.length() + 1];
        for (int i = 0; i < str1.length(); i++) {
            for (int j = 0; j < str2.length(); j++) {
                dp[i][j] = -1;
            }
        }
        return editDistDynRec(str1, str2, str1.length(), str2.length(), dp);
    }

    /**
     * Recursive method called in editDistanceDynTopDown, computes the edit distance between
     * the first string (str1) and the second string (str2), in other words
     * the minimum number of deletion and insertion to transform
     * the second string in the first string.
     * @param str1: First string.
     * @param str2: Second string.
     * @param m: length of first string (str1)
     * @param n: length of second string (str2)
     * @param dp: a integer matrix which stores the result of previous recursive call
     *
     * @return the edit distance between the two given strings (based only on insertion and deletion).
     * @see #editDistanceDynTopDown(String, String) for more information.
     */
    private static int editDistDynRec(String str1, String str2, int m, int n, int dp[][]) {

        // if |s1| = 0 then editDistance(s1,s2) = |s2|
        if (m == 0)
            return n;

        // if |s2| = 0 then editDistance(s1,s2) = |s1|
        if (n == 0)
            return m;

        // if the recursive call has been called previously, return
        // its stored value memorized in the matrix previously
        if (dp[m - 1][n - 1] != -1)
            return dp[m - 1][n - 1];

        // If last characters of two strings are same, ignore last characters and get count for
        // remaining strings.

        // Store the returned value at dp[m-1][n-1]
        // considering 1-based indexing
        if (str1.charAt(m-1) == str2.charAt(n-1))
            return dp[m - 1][n - 1] = editDistDynRec(str1, str2, m - 1, n - 1, dp);

        // If last characters are not same, consider all two
        // operations on last character of first string, recursively
        // compute minimum cost for all those operations and store
        // that value in dp[m-1][n-1].
        return dp[m - 1][n - 1] = 1 + Math.min(editDistDynRec(str1, str2, m, n - 1, dp), // Insert
                                                editDistDynRec(str1, str2, m - 1, n, dp) // Remove
                                                );
    }
}

