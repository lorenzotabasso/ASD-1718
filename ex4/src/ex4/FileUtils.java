package ex4;

import ex4.graph.Edge;
import ex4.graph.Graph;
import ex4.graph.Vertex;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

/**
 * @author Lorenzo Tabasso, mat: 812499
 * @author Andrea Malgaoli, mat: 823429
 *
 * Utils Class to read a file and setUp a data structure
 */
class FileUtils {

    static void GraphCSV(Graph graph, String path) {
        try {
            BufferedReader br = new BufferedReader(new FileReader(path));
            String line = br.readLine();
            while (line != null) {
                String[] fields = line.split(",");
                graph.addEdge(new Edge<>(new Vertex<>(fields[0]), new Vertex<>(fields[1]),Double.parseDouble(fields[2])));
                line = br.readLine();
            }
            br.close();
        }
        catch (IOException e) {
            System.out.println("Error, file not found ...");
        }
    }
}
