package ex2;


import java.io.FileInputStream;
import java.util.HashMap;
import java.util.Scanner;

/**
 * @author Lorenzo Tabasso
 * @author Andrea Malgaroli
 */

class MyDictionary {

    private HashMap<Character, HashMap<Integer, String>> index;
    private Integer sectionsNumber;
    private Integer wordsNumber;

    // COSTRUCTORS ------------------------------------------------------------

    public MyDictionary() {
        this.index = new HashMap<Character, HashMap<Integer, String>>();
        this.sectionsNumber = 0;
        this.wordsNumber = 0;
    }

    // GETTERS-----------------------------------------------------------------

    public HashMap<Character, HashMap<Integer, String>> getIndex() {
        return index;
    }

    public Integer getSectionsNumber() {
        return sectionsNumber;
    }

    public Integer getWordsNumber() {
        return wordsNumber;
    }

    // SETTERS ----------------------------------------------------------------

    public void setIndex(HashMap<Character, HashMap<Integer, String>> index) {
        this.index = index;
    }

    public void setSectionsNumber(Integer sectionsNumber) {
        this.sectionsNumber = sectionsNumber;
    }

    public void setWordsNumber(Integer wordsNumber) {
        this.wordsNumber = wordsNumber;
    }

    public void addSection(Character section) {
        if (!getIndex().containsKey(section)) {
            getIndex().put(section, new HashMap<Integer, String>());
            sectionsNumber++;
        }
    }

    public HashMap<Integer, String> getSection(Character letter) {
        return getIndex().get(letter);
    }

    public void addWord(String word) {
        Character c = word.charAt(0);
        if (!getIndex().containsKey(c)) {
            getIndex().put(c, new HashMap<Integer, String>());
            sectionsNumber++;
        }
        HashMap<Integer, String> section = getIndex().get(c);
        if (!section.containsValue(word)) {
            section.put(wordsNumber, word);
            wordsNumber++;
        }
    }

    public void printSections(){
        for (Character key : getIndex().keySet()) {
            System.out.println("Section: " + key);
        }
    }

    /**
     * Reads and load one word at time from the dataset
     * (wich path had to be specified in datasetPath parameter) into
     * MyDictionary object.
     *
     * @param datasetPath: the path to the dataset to load.
     */

    public void load (String datasetPath) {
        try {
            if (datasetPath == null)
                throw new RuntimeException("Error while opening the file, retry.");

            System.out.println("Loading dataset into Dictionary ...");
            long start = System.currentTimeMillis();

            MyDictionary dict = new MyDictionary();
            Scanner sc = new Scanner(new FileInputStream(datasetPath));
            sc.useDelimiter("\n");

            while (sc.hasNext())
                dict.addWord(sc.nextLine());
            sc.close();

            long end = System.currentTimeMillis();
            System.out.println("Loaded " + dict.sectionsNumber + " Sections and "
                    + dict.wordsNumber + " Words in "
                    + (float)(end - start)/1000 + " seconds.");
        } catch (Exception e) {
            throw new RuntimeException("Error while reading dataset.");
        } // end try-catch

    } // end load method

} // end MyDictionary class