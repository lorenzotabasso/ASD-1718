package ex4;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;

/***
 /**
 * @author Lorenzo Tabasso, mat: 812499
 * @author Andrea Malgaoli, mat: 823429

 * Utils Class to read a file and setUp a data structure
 */
class FileUtils {
    static void setUpArrayFromFile(ArrayList<Long> array, String path) {
        try {
            BufferedReader br = new BufferedReader(new FileReader(path));
            String line = br.readLine();
            while (line != null){
                Long number = Long.parseLong(line);
                array.add(number);
                line = br.readLine();
            }
            br.close();
        }
        catch (IOException e) {
            System.out.println("Error, file not found ...");
        }
        catch (NumberFormatException e) {
            System.out.println("Error, format not valid ...");
        }
    }

    static void setUpWordsArrayFromTextFile(ArrayList<String> array, String path) {
        try {
            BufferedReader br = new BufferedReader(new FileReader(path));
            String line = br.readLine();
            while (line != null) {
                String[] arr = line.split("[\\s]+");
                Collections.addAll(array, arr);
                line = br.readLine();
            }
            br.close();
        }
        catch (IOException e) {
            System.out.println("Error, file not found");
        }

    }

    static void setUpStringArrayFromFile(ArrayList<String> array, String path) {
        try{
            BufferedReader br = new BufferedReader(new FileReader(path));
            String line = br.readLine();
            while (line != null) {
                array.add(line.trim());
                line = br.readLine();
            }
            br.close();
        }
        catch (IOException e) {
            System.out.println("Error, file not found ...");
        }
    }

    static void GraphCSV(Graph graph, String path) {
        try {
            BufferedReader br = new BufferedReader(new FileReader(path));
            String line = br.readLine();
            while (line != null) {
                String[] fields = line.split(",");
                graph.addEdge(new Edge(new Vertex<>(fields[0]), new Vertex<>(fields[1]),Double.parseDouble(fields[2])));
                line = br.readLine();
            }
            br.close();
        }
        catch (IOException e) {
            System.out.println("Error, file not found ...");
        }
    }
}
