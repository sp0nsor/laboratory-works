using UnityEngine;

public class Circle : Shape
{
    private float _radius;

    public override void Draw(Color targetColor)
    {
        LineRenderer lineRenderer = gameObject.AddComponent<LineRenderer>();
        lineRenderer.material = new Material(Shader.Find("Standard"));
        lineRenderer.material.color = targetColor;
        lineRenderer.widthMultiplier = 0.1f;

        int numPoints = 360;

        lineRenderer.positionCount = numPoints + 1;
        lineRenderer.loop = true;

        for (int i = 0; i <= numPoints; i++)
        {
            float angle = i * (2f * Mathf.PI / numPoints);
            float x = _radius * Mathf.Cos(angle);
            float y = _radius * Mathf.Sin(angle);
            lineRenderer.SetPosition(i, new Vector3(x, y, 0f));
        }
    }

    public void SetRadius(float radius)
    {
        _radius = radius;
    }
}
