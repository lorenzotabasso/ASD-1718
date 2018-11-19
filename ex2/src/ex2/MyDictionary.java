package ex2;

import java.util.*;
import java.io.*;

/**
 * @author Lorenzo Tabasso
 * @author Andrea Malgaroli
 */

class MyDictionary {

    public HashMap<Character, HashMap<Integer, String>> index = new HashMap<Character, HashMap<Integer, String>>();
    public Integer sectionsNumber = 0;
    public Integer wordsNumber = 0;

    public void addSection(Character section) {
        if (!index.containsKey(section)) {
            index.put(section, new HashMap<Integer, String>());
            sectionsNumber++;
        }
    }

    public HashMap getSection(Character letter) {
        return index.get(letter);
    }

    public void addWord(String word) {
        Character c = word.charAt(0);
        if (!index.containsKey(c)) {
            index.put(c, new HashMap<Integer, String>());
            sectionsNumber++;
        } else {
            HashMap section = index.get(c);
            if (!section.containsKey(word)) {
                section.put(wordsNumber, word);
                wordsNumber++;
            }
        }

    }

    public void printSections(){
        for (Character var : index.keySet()) {
            char key = var;
            System.out.println("Section: " + key);
        }
    }

    /**
     * This method reads records, from a csv file, with this structure:
     * 'integer field' 'character' 'string field' 'character' 'integer field' 'character' 'floating point field' \n.
     * @param datasetPath: the path to the dataset to load.
     */

    public void load (String datasetPath) {
        try {
            if (datasetPath == null) {
                throw new RuntimeException("Error while opening the file, retry.");
            }
            System.out.println("Loading dataset into Dictionary ...");
            long start = System.currentTimeMillis();

            MyDictionary dict = new MyDictionary();

            BufferedReader br = new BufferedReader(new FileReader(datasetPath));
            while (br.readLine() != null) {
                dict.addWord(br.readLine());
            }
            br.close();

            // 2. For-each Loop
            for (Character key : index.keySet()) {
                System.out.println(key);
            }

            long end = System.currentTimeMillis();
            System.out.println("Loaded " + dict.sectionsNumber + " Sections and " + dict.wordsNumber + " Words in " + (float)(end - start)/1000 + " seconds.");
        }

        catch (Exception e) {
            throw new RuntimeException("Error while reading dataset.");
        }
    }

}