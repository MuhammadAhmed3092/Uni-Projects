import java.io.*;

class Node
{
 String Word;
 String Meaning;
 Node Left;
 Node Right;
 int index=0;
 public Node(String Word, String Meaning)
 {
  this.Word=Word;
  this.Meaning=Meaning;
  this.Left=null;
  this.Right=null;
 }
}

public class Tree
{
 Node Root;
 String Name;
 int index=0;

 public Tree(String Name)
 {
  this.Name=Name;
 }

 public void addEntry(String Word,String Meaning)
 {
  
  Root=addNewNode(Root,Word,Meaning);
 }

 private Node addNewNode(Node node, String word, String meaning)
 {
  if (node==null)
   return new Node(word,meaning);
  else if (node.Word.compareTo(word)<=0)
  {
   node.Left=addNewNode(node.Left,word,meaning);
   return node;
  }
  else
  {
   node.Right=addNewNode(node.Right,word,meaning);
   return node;
  }
 }

 public String findEntry(String word) throws NullPointerException
 {
  Node tempnode=new Node("","");
  find(Root,word,tempnode);
  return tempnode.Meaning;
 }

 private void find(Node node, String word, Node temp) throws NullPointerException
 {
  try
  {
   if (node.Word.compareTo(word)==0)
   {
    temp.Word=node.Word;
    temp.Meaning=node.Meaning;       
    temp.Left=node.Left;
    temp.Right=node.Right;    
   }
   else if (node.Word.compareTo(word)>0)
    find(node.Right,word,temp);
   else if (node.Word.compareTo(word)<0)
    find(node.Left,word,temp);
  }
  catch(Exception e)
  {
   temp.Word=temp.Meaning="No match found";
   temp.Right=temp.Left=null;
  }
 }

 public void deleteEntry(String word) throws NullPointerException
 {
  delete(Root,word);
  System.gc();
 }

 private void delete(Node node, String word) throws NullPointerException
 {
  try
  {
   if (node.Word.compareTo(word)==0)
    node.Word=node.Meaning="";
   else if (node.Word.compareTo(word)>0)
    delete(node.Right,word);
   else if (node.Word.compareTo(word)<0)
    delete(node.Left,word);
  }
  catch(Exception e)
  {
   System.out.println("No match found");
  }
  
 }

 public void displayTree()
 {
  display(Root);
 }

 private void display(Node node)
 {
  if (node==null)
   return;
  else
  {
   display(node.Left);
   if (node.Word!=""||node.Meaning!="")
    System.out.println(node.Word+": "+node.Meaning);
   display(node.Right);
  }
 }

 public void saveTree(int ListSize) throws java.io.IOException
 {
  String List[][]=new String[ListSize][2];
  save(Root,List);
  saveToFile(List,ListSize);
 }

 void save(Node node, String List[][]) throws java.io.IOException {
  if (node == null)
   return;
  else {
   save(node.Left, List);
   if (node.Word != "" && node.Meaning != "") {
    if (index < List.length) {
     List[index][0] = node.Word;
     List[index][1] = node.Meaning;
     index++;
    }
    save(node.Right, List);
   }
  }
 }

 void saveToFile(String List[][],int ListSize) throws java.io.IOException
 {
  String filename=this.Name;
  filename=filename.concat(".txt");
  PrintWriter outfile=new PrintWriter(new FileWriter(filename));
  for (int i=0;i<ListSize;i++)
  {
   outfile.println(List[i][0]);
   outfile.println(List[i][1]);
  }
  outfile.close();
 }

 public void loadTree() throws java.io.IOException, NullPointerException {
  String filename = this.Name;
  filename = filename.concat(".txt");
  BufferedReader infile = new BufferedReader(new FileReader(filename));

  String meaning="Test", word="test";
  while (!(word.compareTo("null") == 0)) {
   word = infile.readLine();
   meaning = infile.readLine();
   if (word == null && meaning==null) {
    break;
   }
  }
  infile.close();
 }

}