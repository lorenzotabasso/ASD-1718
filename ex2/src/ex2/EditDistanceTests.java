package ex2;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * @author Lorenzo Tabasso
 */
public class EditDistanceTests {

    String fileToCorrect[];

//    public static String[] loadText(String pathToFile) {
//        String token;
//        Scanner sc = null;
//
//        try {
//            sc = new Scanner(new File(pathToFile)).useDelimiter("\\s"); // space character
//        } catch (FileNotFoundException e) {
//            e.printStackTrace();
//        }
//
//        List<String> phrase = new ArrayList<String>();
//
//        assert sc != null;
//        while (sc.hasNext()) {
//            token = sc.next();
//            phrase.add(token.replaceAll("[,.:]", ""));
//        }
//        sc.close();
//
//        String[] text = phrase.toArray(new String[0]);
//
//        // only for debug
////        for (String s : text) {
////            System.out.println(s);
////        }
//    }

//    public static void correctText() {
//        MyDictionary dict = new MyDictionary();
//        dict.load("/Volumes/HDD/Lorenzo/Unito/2 Anno/ASD/Progetto/Progetto 2017-2018/laboratorio-algoritmi-2017-18/Datasets/ex2/dictionary.txt");
//
//        String[] phrase = loadText("/Volumes/HDD/Lorenzo/Unito/2 Anno/ASD/Progetto/Progetto 2017-2018/laboratorio-algoritmi-2017-18/Datasets/ex2/correctme.txt");
//
//        for (String word: phrase) {
//
////            EditDistance.editDistanceDyn(word, )
//        }
//    }

    public static void main(String args[]) {

        MyDictionary dict = new MyDictionary();
        String path = "/Volumes/HDD/Lorenzo/Unito/2 Anno/ASD/Progetto/Progetto 2017-2018/laboratorio-algoritmi-2017-18/Datasets/ex2/dictionary.txt";
        dict.load(path);

        String find = dict.getWord('y', "yacht");

        System.out.println(find);

//        String str1 = "casa";
//        String str2 = "cassa";
//
//        System.out.println("Computing the edit distance between: " + str1 + ", " + str2);
//        System.out.println(EditDistance.editDistance( str1 , str2 , str1.length(), str2.length()));
//        System.out.println("DYN: " + EditDistance.editDistanceDyn( str1 , str2 , str1.length(), str2.length()));
//
//        String str3 = "casa";
//        String str4 = "cara";
//
//        System.out.println("Computing the edit distance between: " + str3 + ", " + str4);
//        System.out.println(EditDistance.editDistance( str3 , str4 , str3.length(), str4.length()));
//        System.out.println("DYN: " + EditDistance.editDistanceDyn( str3 , str4 , str3.length(), str4.length()));
//
//        String str5 = "tassa";
//        String str6 = "passato";
//
//        System.out.println("Computing the edit distance between: " + str5 + ", " + str6);
//        System.out.println(EditDistance.editDistance( str5 , str6 , str5.length(), str6.length()));
//        System.out.println("DYN: " + EditDistance.editDistanceDyn( str5 , str6 , str5.length(), str6.length()));
//
//        String str7 = "pioppo";
//        String str8 = "pioppo";
//
//        System.out.println("Computing the edit distance between: " + str7 + ", " + str8);
//        System.out.println(EditDistance.editDistance( str7 , str8 , str7.length(), str8.length()));
//        System.out.println("DYN: " + EditDistance.editDistanceDyn( str7 , str8 , str7.length(), str8.length()));
    }
}
