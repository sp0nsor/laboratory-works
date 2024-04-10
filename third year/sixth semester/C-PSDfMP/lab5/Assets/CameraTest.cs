using System;
using System.Collections;
using System.Collections.Generic;
using UnityEditor;
using UnityEngine;
using UnityEngine.UI;

public class CameraTest : MonoBehaviour
{
    private WebCamTexture _webCamTexture;
    public RawImage RawImage;

    private void Start()
    {
        _webCamTexture = new WebCamTexture();
        RawImage.texture = _webCamTexture;
        _webCamTexture.Play();
    }

    public void OnShoot()
    {
        _webCamTexture.Pause();
    }

    public void OnPlay()
    {
        _webCamTexture.Play();
    }
}
