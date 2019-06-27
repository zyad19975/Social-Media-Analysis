using UnityEngine;
using System.Collections;
using UnityEngine.SceneManagement;

public class Menu : MonoBehaviour {

	// Use this for initialization
	void Start () {
	
	}
	
	// Update is called once per frame
	void Update () {
	
	}

	public void Open1(){
		SceneManager.LoadScene("Main");
	} 

	public void Open2(){
		SceneManager.LoadScene("closeness");
	} 

	public void Exit(){
		Application.Quit();
	} 
}
