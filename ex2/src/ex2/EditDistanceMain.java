package ex2;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

/**
 * @author Lorenzo Tabasso, mat: 812499
 * @author Andrea Malgaoli, mat: 823429
 */

public class EditDistanceMain {

    /*
    FOR COMPILING AND RUNNING (for better information see README.md in "laboratorio-algoritmi-2017-18/ex2")
    1. Go with the terminal inside "laboratorio-algoritmi-2017-18/ex2/src"
    2. For compile main launch the next commmand:
        "javac ex2/EditDistance.java ex2/EditDistanceMain.java"
    3. For execute main launch the next commmand:
        "java ex2/EditDistanceMain"
     */

    public static void main(String[] args) {
        // paths to the datasets:
        String pathToDictionary = "/Volumes/HDD/Lorenzo/Unito/2 Anno/ASD/Progetto/Progetto 2017-2018/laboratorio-algoritmi-2017-18/Datasets/ex2/dictionary.txt";
        String pathToText = "/Volumes/HDD/Lorenzo/Unito/2 Anno/ASD/Progetto/Progetto 2017-2018/laboratorio-algoritmi-2017-18/Datasets/ex2/correctme.txt";

        ArrayList<String> dictionary = new ArrayList<String>();
        ArrayList<String> text = new ArrayList<String>();;

        try {
            dictionary = loadDictionary(pathToDictionary);
            text = loadText(pathToText);
        } catch (FileNotFoundException e) {
            System.out.println("Error while opening one of the dataset, maybe path is wrong. Retry!");
            e.printStackTrace();
        }

        doEditDistanceDynBottomUp(dictionary, text);
        doEditDistanceDynTopDown(dictionary, text);
    }

    /**
     * It executes the editDistanceDynBottomUp() method on all the words contained in correctme.txt,
     * comparing them one at time with all the word in a dictionary in order to find all the typos.
     *
     * @param dictionary: the dictionary to be used in order to compare words in the editDistanceDynBottomUp() method.
     * @param text: an ArrayList<String> which contains the text to be correct.
     */
    private static void doEditDistanceDynBottomUp(ArrayList<String> dictionary, ArrayList<String> text) {
        long start = System.currentTimeMillis();
        System.out.println("\nBEGIN OF EDIT DISTANCE DYN, BOTTOM UP VERSION --------------- [Timer reset to 0]"); // 80 chars

        for(String wordInText: text){
            ArrayList<String> minEDPerWords = new ArrayList<String>();
            int min = Integer.MAX_VALUE;

            for(String wordInDictionary: dictionary){
                int editDistance = EditDistance.editDistanceDynBottomUp(wordInDictionary, wordInText);

                if(editDistance < min){
                    min = editDistance;
                    minEDPerWords.clear();
                    minEDPerWords.add(wordInDictionary);
                }
                else if(editDistance == min){
                    minEDPerWords.add(wordInDictionary);
                }
            }
            if(min != 0){
                System.out.println("\nError in word: " + wordInText + ", possible corrections:");
                for(String corr: minEDPerWords)
                    System.out.println("\t" + corr);
            }
        }

        long end = System.currentTimeMillis();
        System.out.println("\nEND OF EDIT DISTANCE DYN, BOTTOM UP VERSION ------- [Finished in "
                + (float)(end - start)/1000 + " seconds]"); // 80 chars
    }

    /**
     * It executes the editDistanceDynTopDown() method on all the words contained in correctme.txt,
     * comparing them one at time with all the word in a dictionary in order to find all the typos.
     *
     * @param dictionary: the dictionary to be used in order to compare words in the editDistanceDynTopDown() method.
     * @param text: an ArrayList<String> which contains the text to be correct.
     */
    private static void doEditDistanceDynTopDown(ArrayList<String> dictionary, ArrayList<String> text) {
        long start = System.currentTimeMillis();
        System.out.println("\nBEGIN OF EDIT DISTANCE DYN, TOP DOWN VERSION ---------------- [Timer reset to 0]"); // 80 chars

        for(String wordInText: text){
            ArrayList<String> minEDPerWords = new ArrayList<String>();
            int min = Integer.MAX_VALUE;

            for(String wordInDictionary: dictionary){
                int editDistance = EditDistance.editDistanceDynTopDown(wordInDictionary, wordInText);

                if(editDistance < min){
                    min = editDistance;
                    minEDPerWords.clear();
                    minEDPerWords.add(wordInDictionary);
                }
                else if(editDistance == min){
                    minEDPerWords.add(wordInDictionary);
                }
            }
            if(min != 0){
                System.out.println("\nError in word: " + wordInText + ", possible corrections:");
                for(String corr: minEDPerWords)
                    System.out.println("\t" + corr);
            }

        }

        long end = System.currentTimeMillis();

        System.out.println("\nEND OF EDIT DISTANCE DYN, TOP DOWN VERSION -------- [Finished in "
                + (float)(end - start)/1000 + " seconds]"); // 80 chars
    }

    /**
     * Support function used in main(). It loads all the words contained in the dataset at the specified path
     * into an ArrayList<String> which will represent the dictionary to use in doEditDistanceDynBottomUp()
     * and doEditDistanceDynTopDown() methods.
     *
     * @param pathToDataset: the path to the dataset.
     *
     * @return An ArrayList<String> who represent the dictionary to use. It contains all the words of the dataset.
     * @throws FileNotFoundException if the specified path to the dataset is wrong.
     */
    private static ArrayList<String> loadDictionary(String pathToDataset) throws FileNotFoundException {
        ArrayList<String> dictionary = new ArrayList<String>();

        System.out.println("Loading dataset into Dictionary ...");
        long start = System.currentTimeMillis();

        Scanner sc = new Scanner(new FileInputStream(pathToDataset));
        sc.useDelimiter("\n");

        while (sc.hasNextLine()) {
            dictionary.add(sc.nextLine());
        }
        sc.close();

        long end = System.currentTimeMillis();
        System.out.println("Loaded " + dictionary.size() + " Words in "
                + (float)(end - start)/1000 + " seconds.");

        return dictionary;
    }

    /**
     * Support function used in main(). It loads all the words contained in the text at the specified path
     * into an ArrayList<String> which will represent the text to correct using doEditDistanceDynBottomUp()
     * and doEditDistanceDynTopDown() methods.
     *
     * @param pathToFile: the path to the text.
     *
     * @return An ArrayList<String> which contains all the words of the text.
     * @throws FileNotFoundException if the specified path to the text is wrong.
     */
    private static ArrayList<String> loadText(String pathToFile) throws FileNotFoundException {
        System.out.println("Loading text ...");
        String token;
        Scanner sc = new Scanner(new File(pathToFile)).useDelimiter("\\s"); // space character

        ArrayList<String> text = new ArrayList<String>();

        while (sc.hasNext()) {
            token = sc.next();
            text.add(token.toLowerCase().replaceAll("[,.:]", ""));
        }
        sc.close();

        System.out.println("Text loaded.");

        return text;
    }
}
