package ex4;

import java.util.Collection;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;
import java.util.stream.Collectors;

/**
 * @author Lorenzo Tabasso, mat: 812499
 * @author Andrea Malgaoli, mat: 823429
 *
 * Graph class
 *
 * @param <T> Generic type
 */
public class Graph<T> {
    private final Set<Vertex<T>> vertices;
    private final Set<Edge<T>> edges;
    private final Map<Vertex<T>, Set<Edge<T>>> adjList;
    private final boolean isOriented;

    /**
     * Graph constructor
     *
     * @param isOriented Graph type
     */
    public Graph(boolean isOriented) {
        vertices = new HashSet<>();
        edges = new HashSet<>();
        adjList = new HashMap<>();
        this.isOriented = isOriented;
    }

    /**
     * Checks the graph's oriented property
     *
     * @return true if the graph is oriented, false otherwise
     */
    public boolean isOriented() {
        return isOriented;
    }

    /**
     * Checks if the Vertex v is contained in Set<Vertex> vertices
     *
     * @param v Vertex
     * @return true if it is contained, false otherwise
     */
    public boolean contains(Vertex<T> v) {
        return vertices.contains(v);
    }

    /**
     * Add the Vertex v in Set<Vertex> vertices
     *
     * @param v Vertex
     * @return true if it is added, false otherwise
     */
    public boolean addVertex(Vertex<T> v) {
        return vertices.add(v);
    }

    /**
     * Adds all vertices from the given set to this set of vertices
     *
     * @param vertices Collection of Vertices
     * @return true if it is all added, false otherwise
     */
    public boolean addVertices(Collection<Vertex<T>> vertices) {
        return this.vertices.addAll(vertices);
    }

    /**
     * Removes the Vertex v from Set<Vertex> vertices
     *
     * @param v Vertex
     * @return true if it is removed, false otherwise
     */
    public boolean removeVertex(Vertex<T> v) {
        return vertices.remove(v);
    }

    /**
     * Adds Edge e in the set of edges
     *
     * @param e Edge
     * @return true if it is added
     */
    public boolean addEdge(Edge<T> e) {
        if (isOriented) {
            return addEdgeOriented(e);
        }
        else {
            Edge<T> toReturn = new Edge<T>(e.getVertex2(), e.getVertex1(), e.getWeight());
            return addEdgeOriented(e) && addEdgeOriented(toReturn);
        }
    }

    /**
     * Support method used in addEdge()
     */
    private boolean addEdgeOriented(Edge<T> e) {
        edges.add(e);

        vertices.add(e.getVertex1());
        vertices.add(e.getVertex2());

        adjList.putIfAbsent(e.getVertex1(), new HashSet<>());
        adjList.putIfAbsent(e.getVertex2(), new HashSet<>());
        adjList.get(e.getVertex1()).add(e);
        adjList.get(e.getVertex1()).add(e);

        return true;
    }

    /**
     * Removes an edge from edges set
     *
     * @param e Edge
     * @return true if it is removed, false otherwise
     */
    public boolean removeEdge(Edge<T> e) {
        if (!edges.remove(e))
            return false;

        Set<Edge<T>> edgesOfV1 = adjList.get(e.getVertex1());
        Set<Edge<T>> edgesOfV2 = adjList.get(e.getVertex2());

        if (edgesOfV1 != null)
            edgesOfV1.remove(e);
        if (edgesOfV2 != null)
            edgesOfV2.remove(e);

        return true;
    }

    /**
     * Gets adjacent vertices from v
     *
     * @param v Vertex
     * @return Set<Vertex> adjacent of v
     */
    public Set<Vertex<T>> getAdjVertices(Vertex<T> v) {
        return adjList.get(v).stream()
                .map((Edge<T> e) -> e.getVertex1().equals(v) ? e.getVertex2() : e.getVertex1())
                .collect(Collectors.toSet());
    }

    /**
     * Gets the set of vertices
     *
     * @return Set<Vertex>
     */
    public Set<Vertex<T>> getVertices() {
        return Collections.unmodifiableSet(vertices);
    }

    /**
     * Gets the set of edges
     *
     * @return Set<Edge>
     */
    public Set<Edge<T>> getEdges() {
        return Collections.unmodifiableSet(edges);
    }

    /**
     * Gets an HashMap of vertices adjacent to it
     *
     * @return HashMap<Vertex, Set<Edge>>
     */
    public Map<Vertex<T>, Set<Edge<T>>> getAdjList() {
        return Collections.unmodifiableMap(adjList);
    }

    /**
     * Overrides the behavior of the method to create a string starting from the
     * Graph object
     *
     * @return Graph object printed into String
     */
    @Override
    public String toString() {
        String s = "";
        for (Edge<T> e : edges)
            s += "from vertex " + e.getVertex1() + " to vertex " + e.getVertex2() + " weight " + e.getWeight() + "\n";
        return s;
    }

    /**
     * Gets edge's weight
     *
     * @param v1 From Vertex
     * @param v2 To Vertex
     * @return the weight of edge from v1 to v2
     */
    public double getWeight(Vertex<T> v1, Vertex<T> v2) {
        Set<Edge<T>> adj = adjList.get(v1);
        for (Edge<T> e : adj)
            if (e.getVertex1().equals(v1) && e.getVertex2().equals(v2))
                return e.getWeight();
        return 0;
    }

    /**
     * Gets graph's weight
     *
     * @return the weight of the graph
     */
    public double weight() {
        double weight = 0;
        for (Edge<T> e : edges)
            weight += e.getWeight();
        return isOriented ? weight : weight / 2;
    }
}