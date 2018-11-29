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
     * FOR COMPILE:
     * go in laboratorio-algoritmi-2017-18/ex2/src/ directory, and launch the next command,
     *
     * "javac ex2/*.java" (which will compile all the .java files in ex2 package)
     * "java ex2/EditDistanceMain" (which will run the main down below)
     */

    public static void main(String[] args) {
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
