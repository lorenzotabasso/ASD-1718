package ex3;

import java.util.ArrayList;
import java.util.HashMap;

/**
 * @author Lorenzo Tabasso, mat: 812499
 * @author Andrea Malgaoli, mat: 823429
 *
 * @param <T> Generic type
 * @param <P> Priority
 */
public class PQueue<T, P extends Comparable<P>>
{
    private ArrayList<QueueItem<T, P>> list;
    private HashMap<T, Integer> index;

    public PQueue()
    {
        list = new ArrayList<>();
        index = new HashMap<>();
    }

    /**
     * Add the element to the last level of the heap.
     *
     * @return true if the element is inserts with priority
     */
    public boolean insert(T elem, P priority)
    {
        if (isPresent(elem) == null)
        {
            list.add(new QueueItem<>(elem, priority));
            int i = list.size() - 1;
            int parent = parent(i);
            index.put(elem, i);
            while (parent != i && list.get(i).getPriority().compareTo(
                    list.get(parent).getPriority()) < 0)
            {
                swap(i, parent);
                i = parent;
                parent = parent(i);
            }
            return true;
        }
        return false;
    }

    /**
     * Sets newPriority to the element (if any)
     *
     * @param elem the item
     * @param newPriority new priority to be set
     */
    public void setPriority(T elem, P newPriority)
    {
        Integer i = isPresent(elem);
        if (i == null)
            return;

        QueueItem<T, P> temp = list.get(i);
        temp.setPriority(newPriority);
        list.set(i, temp);
        index.put(temp.getItem(), i);
        heapify(i);
        int parent = parent(i);
        while (parent != i && list.get(i).getPriority().compareTo(
                list.get(parent).getPriority()) < 0)
        {
            swap(i, parent);
            i = parent;
            parent = parent(i);
        }
    }

    /**
     * Checks if the item in the queue is present
     *
     * @return index of element if exist, null otherwise
     */
    public Integer isPresent(T elem)
    {
        return index.get(elem);
    }

    /**
     * Builds the heap starting from the first half of the elements in the list
     */
    public void buildHeap()
    {
        for (int i = list.size() / 2; i >= 0; i--)
            heapify(i);
    }

    /**
     * Replace the root of the heap with the last element, then sort the heap
     * from the new root.
     */
    private void removeFirst()
    {
        if (isEmpty())
            return;

        T first = peek();
        if (list.size() == 1)
        {
            list.remove(0);
            index.remove(first);
            return;
        }
        else
        {
            QueueItem<T, P> e = list.remove(list.size() - 1);
            list.set(0, e);
            index.put(e.getItem(), 0);
            index.remove(first);
        }
        heapify(0);
    }

    /**
     * Gets the first element and deletes it from the queue: Uses methods peek()
     * + removeFirst() to do it.
     *
     * @return <T> element in first position
     */
    public T pullFirst()
    {
        if(isEmpty())
            return null;
        T t = peek();
        removeFirst();
        return t;
    }

    /**
     * Restores the heap ordering property at the specified index by pushing it
     * downwards to its correct location
     *
     * @param i int index
     */
    private void heapify(int i) throws IllegalArgumentException
    {
        if (i >= list.size())
            throw new IllegalArgumentException();

        int left = left(i);
        int right = right(i);
        int smallest;

        if (list.get(left).getPriority().compareTo(
                list.get(i).getPriority()) < 0)
            smallest = left;
        else
            smallest = i;
        if (list.get(right).getPriority().compareTo(
                list.get(smallest).getPriority()) < 0)
            smallest = right;

        if (smallest != i)
        {
            swap(i, smallest);
            heapify(smallest);
        }
    }

    /**
     * Gets root element
     *
     * @return <T> element in first position
     */
    public T peek()
    {
        if(isEmpty())
            return null;
        return list.get(0).getItem();
    }

    /**
     * Checks if queue is empty
     *
     * @return true if is it empty, false otherwise
     */
    public boolean isEmpty()
    {
        return list.isEmpty();
    }

    /**
     * Returns the index of the right child if exists
     *
     * @param i int index
     * @return the index of the right child if exists, i otherwise
     */
    private int right(int i)
    {
        if (2 * i + 2 < list.size())
            return 2 * i + 2;
        return i;
    }

    /**
     * Returns the index of the left child if exists
     *
     * @param i int index
     * @return the index of the left child if exists, i otherwise
     */
    private int left(int i)
    {
        if (2 * i + 1 < list.size())
            return 2 * i + 1;
        return i;
    }

    /**
     * Returns the index of the parent of the child
     *
     * @param i int index
     * @return the index of the parent of the child if exists, i otherwise
     */
    private int parent(int i)
    {
        if (i % 2 == 1)
            return i / 2;
        return (i - 1) / 2;
    }

    /**
     * Swap in place the elements in the list in position i and parent, and
     * saves the references in index.
     *
     * @param i int index
     * @param parent int index parent's index
     */
    private void swap(int i, int parent)
    {
        QueueItem<T, P> temp = list.get(parent);
        list.set(parent, list.get(i));
        index.put(list.get(i).getItem(), parent);
        list.set(i, temp);
        index.put(temp.getItem(), i);
    }

    /**
     * Overrides the behavior of the method to create a string starting from the
     * PriorityQueue object
     *
     * @return PriorityQueue object printed into String
     */
    @Override
    public String toString()
    {
        StringBuilder s = new StringBuilder("Queue: \n");
        for (QueueItem<? extends T, ? extends P> item : list)
            s.append(item).append("\n");
        return s.toString();
    }
}
