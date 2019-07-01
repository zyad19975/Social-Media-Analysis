using UnityEngine;
using System.Collections;
using System.Collections.Generic;
using UnityEngine.UI;
using System.IO;
using UnityEngine.SceneManagement;

public class GameManager : MonoBehaviour {
	public GameObject node;
	Text t; 
	int numberOfNodes = 0;
	GameObject myNode;
	public List<GameObject> nodesList;

	public Line ConnectionsClass;
	public Image myImage;

	public Read R;
	int index = 2;

	string readPath;
	public Image background;
	// Use this for initialization
	void Start () {

		Scene scene = SceneManager.GetActiveScene();
		if(scene.name == "Main"){
			readPath = Application.dataPath + "/degree_centrality.txt"; }
		else{
			readPath = Application.dataPath + "/closeness_centrality.txt"; }
		
		R.ReadFile (readPath);
		R.stringToInt ();

		for (int i = 0; i < R.intList [0]; i++) {
			CreateNode (new Vector3(Random.Range(50.0f, 350f),Random.Range(50.0f, 300f),0));
		}
			
	
		for (int j = 0; j < R.intList [1]; j++) {
			
			Connect2Points (R.intList [index],R.intList [index +1]);
			index += 2;
		}
		background.transform.SetSiblingIndex(0);

		for (int i = 0; i < R.intList [0]; i++) {
			nodesList [i].GetComponent<RectTransform> ().localScale += new Vector3 (R.intList [index +i]/7f, R.intList [index +i]/7f);
		}

	}
	
	// Update is called once per frame
	void Update () {

		if (Input.GetKeyDown(KeyCode.R))
		{
			Scene scene = SceneManager.GetActiveScene();
			if(scene.name == "Main"){
				SceneManager.LoadScene("Main"); }
			else{
				SceneManager.LoadScene("closeness"); }
		}

		if (Input.GetKeyDown(KeyCode.B))
		{
			SceneManager.LoadScene("Menu");
		}
	}

	void CreateNode(Vector3 pos){

		if (R.intList [0] <= 20){

		while (Physics2D.OverlapCircle (pos, 100) == true) {
			pos = new Vector3 (Random.Range (50.0f, 750f), Random.Range (50.0f, 550f), 0);
		}
		myNode = (GameObject)Instantiate(node , pos, Quaternion.identity);

		myNode.transform.parent = GameObject.FindGameObjectWithTag ("Player").transform;

		t = myNode.transform.GetChild (0).gameObject.GetComponent<Text>();
		t.text = numberOfNodes.ToString ();
		nodesList.Add (myNode);
		numberOfNodes++;
		}

		else {
			while (Physics2D.OverlapCircle (pos, 30) == true) {
				pos = new Vector3 (Random.Range (50.0f, 750f), Random.Range (50.0f, 550f), 0);
			}
			myNode = (GameObject)Instantiate(node , pos, Quaternion.identity);

			myNode.transform.parent = GameObject.FindGameObjectWithTag ("Player").transform;
			myNode.GetComponent<RectTransform> ().localScale = new Vector3 (myNode.GetComponent<RectTransform> ().localScale.x/2f, myNode.GetComponent<RectTransform> ().localScale.y/2f);
			t = myNode.transform.GetChild (0).gameObject.GetComponent<Text>();
			t.text = numberOfNodes.ToString ();
			nodesList.Add (myNode);
			numberOfNodes++;
		}

		}


	void Connect2Points( int s , int e){
    	 
		 ConnectionsClass.a = nodesList [s].GetComponent<RectTransform> ();
		 ConnectionsClass.b = nodesList [e].GetComponent<RectTransform> ();
		 ConnectionsClass.L = Instantiate(myImage);
		 ConnectionsClass.L.transform.parent = GameObject.FindGameObjectWithTag ("Player").transform;
		 ConnectionsClass.L.transform.SetSiblingIndex(0);
		 ConnectionsClass.Connect ();
	}
		
}
	