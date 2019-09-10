import java.util.*;
import java.lang.*; 
import java.io.*; 

public abstract class Animal {
   String name;
   int legs;
}

public class Dog extends Animal {
	public Dog (String n, int l) {
		name = n;
		legs = l;
	}

	public String toString(){
		return name;
	}
}
// Write a comparator class AnimalCompare with the 
// required method and the required parameters.
// The method must consider name first (ignore case), 
// then legs to break a tie.
class AnimalCompare implements Comparable<Dog> {
    public int compare(Dog d1, Dog d2){
    	return d1.legs.compareTo(d2.legs);
    }
}

class Main {
	public static void main (String [] args){
		Collections<Dog> pack = new ArrayList<Dog>( );

		pack.add (new Dog("Emily", 8));
		pack.add (new Dog("Emily", 3));
		pack.add (new Dog("Ahmad", 78));

		System.out.println(pack);
		Collections.sort(pack, new AnimalCompare()); 

	}


}
