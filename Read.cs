using UnityEngine;
using System.Collections;
using System.Collections.Generic;
using System.IO;

public class Read : MonoBehaviour {

	//string readPath;
	public List<string> stringList = new List<string> ();
	public List<int> intList = new List<int> ();
	// Use this for initialization
	void Start () {
		//readPath = Application.dataPath + "/test.txt";



	}
	
	// Update is called once per frame
	void Update () {
	}

	public void ReadFile(string filePath){
	
		StreamReader sReader = new StreamReader (filePath);
		while (!sReader.EndOfStream) {
			string line = sReader.ReadLine ();
			stringList.Add (line);
		}
	
		sReader.Close ();
	}

	public void stringToInt(){

		for (int i = 0; i < stringList.Count ; i++) {
			string[] s = stringList[i].Split(" "[0]);

			for (int j = 0; j < s.Length ; j++) {
				int x = int.Parse(s[j]);
				intList.Add (x);
			}
		}
	}



}
