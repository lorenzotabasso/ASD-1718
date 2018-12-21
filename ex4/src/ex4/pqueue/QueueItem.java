package ex4.pqueue;

/**
 /**
 * @author Lorenzo Tabasso, mat: 812499
 * @author Andrea Malgaoli, mat: 823429
 *
 * @param <T> Generic type
 * @param <P> Priority
 */
public class QueueItem< T, P >{
    private T item;
    private P priority;

    public QueueItem(T item, P priority){
        this.item = item;
        this.priority = priority;
    }

    public T getItem(){
        return item;
    }

    public void setElem(T elem){
        this.item = elem;
    }

    public P getPriority(){
        return priority;
    }

    public void setPriority(P priority){
        this.priority = priority;
    }

    @Override
    public String toString(){
        return "Value: " + item + " Priority: " + priority;
    }
}