package ex2;


import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.UnsupportedEncodingException;
import java.nio.charset.StandardCharsets;
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

    // OTHER METHODS ----------------------------------------------------------

    public void addSection(Character section) {
        getIndex().put(section, new HashMap<Integer, String>());
        sectionsNumber++;
    }

    public HashMap<Integer, String> getSection(Character letter) {
        return getIndex().get(letter);
    }

    public void addWord(Integer key, String word) {
        Character c = word.charAt(0);

        if (!getIndex().containsKey(c)) {
            addSection(c);
        }
            HashMap<Integer, String> section = getIndex().get(c);

            if (!section.containsValue(word)) {
                section.put(key, word);
                wordsNumber++;
            }
    }

    public String getWord(char sectionInitial, String word) {

        long start = System.currentTimeMillis(); // for timing

        HashMap<Integer, String> section = getIndex().get(sectionInitial);

        int i = 0;
        boolean found = false;
        String result = "";
        while (i < section.size() && !found) {
            if (section.get(i).equals(word)) {
                result = section.get(i);
                found = true;
            }

            i++;
        }

        long end = System.currentTimeMillis();
        System.out.println("Found word [" + word + "] in " + (float)(end - start)/1000 + " seconds.");

        return result;
    }

    public String[] getWordsInSection(char sectionInitial) {
        HashMap<Integer, String> section = getIndex().get(sectionInitial);
        String[] result = new String[section.size()];
        for (int i = 0; i < section.size(); i++) {
            result[i] = section.get(i);
        }

        return result;
    }

    public HashMap<Integer, String> getSection(char sectionInitial) {
        return getIndex().get(sectionInitial);
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
            System.out.println("Loading dataset into Dictionary ...");
            long start = System.currentTimeMillis();

            Scanner sc = new Scanner(new FileInputStream(datasetPath));
            sc.useDelimiter("\n");

            String cl = sc.nextLine();
            Integer key = 0;

            Character lastIndex = cl.charAt(0); // Only for debug purposes
            Integer lastKey = 0; // Only for debug purposes

            while (sc.hasNext() && key < 10) {

                if (!lastIndex.equals(cl.charAt(0))) {

                    lastIndex = cl.charAt(0); // Only for debug purposes
                    lastKey = key; // Only for debug purposes
                    System.out.println("\tKey updated to " + lastIndex +
                            ", \tWRfLI: " + lastKey +
                            ", \tTW: "+ this.wordsNumber +
                            ", \tFWoNI: " + cl);

                    key = 0;

                }

                this.addWord(key, cl);
                key++;

                cl = sc.nextLine();
            }
            sc.close();

            long end = System.currentTimeMillis();
            System.out.println("Loaded " + this.sectionsNumber + " Sections and "
                    + this.wordsNumber + " Words in "
                    + (float)(end - start)/1000 + " seconds.");

        } catch (FileNotFoundException e) {
            System.out.println("Error while opening the dataset, maybe path is wrong. Retry!");
            e.printStackTrace();
        } // end try-catch

    } // end load method

} // end MyDictionary class