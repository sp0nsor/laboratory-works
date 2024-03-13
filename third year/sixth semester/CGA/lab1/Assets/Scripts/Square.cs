using UnityEngine;

public class Square : Shape
{
    private float _sideLength;

    public Square(float sideLength)
    {
        _sideLength = sideLength;
    }

    public override void Draw(Color targetClor)
    {
        LineRenderer lineRenderer = gameObject.AddComponent<LineRenderer>();
        lineRenderer.material = new Material(Shader.Find("Standard"));
        lineRenderer.material.color = targetClor;
        lineRenderer.widthMultiplier = 0.1f;

        Vector3[] squareVertices = new Vector3[]
        {
            new Vector3(-_sideLength,-_sideLength, 0f),
            new Vector3(_sideLength,-_sideLength, 0f),
            new Vector3(_sideLength,_sideLength, 0f),
            new Vector3(-_sideLength,_sideLength, 0f),
            new Vector3(-_sideLength,-_sideLength, 0f),
        };

        lineRenderer.positionCount = squareVertices.Length;
        lineRenderer.SetPositions(squareVertices);
    }

    public void SetLength(float sideLength)
    {
        _sideLength = sideLength;
    }
}
