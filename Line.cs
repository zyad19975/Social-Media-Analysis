using UnityEngine;
using System.Collections;
using UnityEngine.UI;

public class Line : MonoBehaviour {

	public RectTransform a;
	public RectTransform b;
	public Image L;
	// Use this for initialization
	void Start () {
		//Connect ();
	}
	
	// Update is called once per frame
	void Update () {
	
	}

	public void Connect(){
	
		Vector3 diff = a.position - b.position ;
		L.GetComponent<RectTransform>().sizeDelta = new Vector2( diff.magnitude, 4);
		L.GetComponent<RectTransform>().pivot = new Vector2(1f, 0f);
		L.GetComponent<RectTransform>().position = a.position;
		float angle = Mathf.Atan2(diff.y, diff.x) * Mathf.Rad2Deg;
		L.GetComponent<RectTransform>().rotation = Quaternion.Euler(0,0, angle);


	
	}
}


