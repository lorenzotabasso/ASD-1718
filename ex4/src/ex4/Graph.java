package ex4;

import java.util.*;

/**
 * @author Lorenzo Tabasso, mat: 812499
 * @author Andrea Malgaoli, mat: 823429
 *
 * Graph class
 *
 * @param <T> Generic type
 */
public class Graph<T> {
    private final Map<Vertex<T>, LinkedList<Edge<T>>> adjList;
    private final boolean isOriented;

    /**
     * Graph constructor
     *
     * @param isOriented Graph type
     */
    public Graph(boolean isOriented) {
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
     * Checks if the Vertex v is contained in the Graph
     *
     * @param v Vertex
     * @return true if it is contained, false otherwise
     */
    public boolean contains(Vertex<T> v) {
        return adjList.containsKey(v);
    }

    /**
     * Adds the Vertex v in the Graph.
     *
     * @param v Vertex
     */
    public void addVertex(Vertex<T> v) {
        if (!adjList.containsKey(v))
            adjList.put(v, new LinkedList<>());
    }

    /**
     * Removes the Vertex v from Set<Vertex> vertices
     *
     * @param v Vertex
     */
    public void removeVertex(Vertex<T> v) {
        adjList.remove(v);
    }

    /**
     * Adds Edge<T> e in the Graph.
     *
     * @param e the Edge to be added in the Graph.
     */
    public void addEdge(Edge<T> e) {
        if (isOriented) {
            addEdgeOriented(e);
        }
        else {
            Edge<T> eReverse = new Edge<>(e.getVertex2(), e.getVertex1(), e.getWeight());
            addEdgeOriented(e);
            addEdgeOriented(eReverse);
        }
    }

    /**
     * Support method used in addEdge()
     *
     * @param e the Edge<T> to be added to the Graph.
     * @see #addEdge(Edge)
     */
    private void addEdgeOriented(Edge<T> e) {
        // first we check if both the vertices of the edge
        // are already inside the adjList, if don't, then we add them.
        adjList.putIfAbsent(e.getVertex1(), new LinkedList<>());
        adjList.putIfAbsent(e.getVertex2(), new LinkedList<>());

        // finally we put the edge in the adjList
        adjList.get(e.getVertex1()).add(e);
    }

    /**
     * Removes an edge from the Graph.
     *
     * @param e the Edge<T> to be removed
     * @return true if it's removed, false otherwise
     */
    public boolean removeEdge(Edge<T> e) {
        if (this.isOriented) {
            LinkedList<Edge<T>> edges = adjList.get(e.getVertex1());
            return edges.remove(e);
        } else {
            LinkedList<Edge<T>> edgesV1 = adjList.get(e.getVertex1());
            LinkedList<Edge<T>> edgesV2 = adjList.get(e.getVertex2());

            Edge<T> eReverse = new Edge<>(e.getVertex2(), e.getVertex1(), e.getWeight());

            return edgesV1.remove(e) && edgesV2.remove(eReverse);
        }
    }

    /**
     * It returns a LinkedList<T> which contains all the vertex of the Graph.
     *
     * @return a LinkedList<T> which contains all the vertex of the Graph.
     * @see GraphTests
     * @see PrimTest
     */
    public LinkedList<Vertex<T>> getVertices() {
        return new LinkedList<>(adjList.keySet());
    }

    /**
     * Gets adjacent vertices from the Vertex<T> v.
     *
     * @param v Vertex from which start the computation.
     * @return a LinkedList<Vertex<T> containing all the adjacent vertices of the Vertex<T> v.
     */
    public LinkedList<Vertex<T>> getAdjVertices(Vertex<T> v) {
        LinkedList<Vertex<T>> res = new LinkedList<>();
        for (Edge<T> e: adjList.get(v)) {
            res.add(e.getVertex2());
        }
        return res;
    }

    /**
     * It returns a LinkedList<T> which contains all the edges of the Graph.
     *
     * @return a LinkedList<T> which contains all the edges of the Graph.
     * @see GraphTests
     * @see PrimTest
     */
    public LinkedList<Edge<T>> getEdges() {
        LinkedList<Edge<T>> res = new LinkedList<>();
        for (Vertex<T> v : adjList.keySet()) {
            res.addAll(adjList.get(v));
        }
        return res;
    }

    /**
     * Gets edge's weight
     *
     * @param v1 start vertex of the Edge to compute the weight
     * @param v2 final vertex of the Edge to compute the weight
     * @return the weight of edge from the first vertex v1 to the final vertex v2
     */
    public double getEdgeWeight(Vertex<T> v1, Vertex<T> v2) {
        LinkedList<Edge<T>> res = adjList.get(v1);
        for (Edge<T> e : res)
            if (e.getVertex1().equals(v1) && e.getVertex2().equals(v2))
                return e.getWeight();
        return 0;
    }

    /**
     * Gets graph's weight.
     *
     * @return the weight of the graph.
     */
    public double getGraphWeight() {
        double weight = 0;
        for (Vertex<T> v : adjList.keySet()) {
            for (Edge<T> e: adjList.get(v)) {
                weight += e.getWeight();
            }
        }
        return isOriented ? weight : weight / 2;
    }

    /**
     * Overrides the behavior of the method to create a string to represent the
     * Graph object
     *
     * @return Graph object printed into String
     */
    @Override
    public String toString() {
        StringBuilder s = new StringBuilder();
        for (Vertex<T> v : adjList.keySet()) {
            for (Edge<T> e: adjList.get(v)) {
                s.append("from vertex ").
                        append(e.getVertex1()).append(" to vertex ").
                        append(e.getVertex2()).append(" weight ").
                        append(e.getWeight()).append("\n");
            }
        }
        return s.toString();
    }
}
