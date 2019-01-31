#include "stdafx.h"
#include "TestVertex.h"

void TestVertex::Initialize()
{
	shader = new Shader(Shaders + L"045_Vertex.fx");

	vertices[0].Position = D3DXVECTOR3(-0.5f, -0.5f, 0.0f);
	vertices[1].Position = D3DXVECTOR3(-0.5f,  0.5f, 0.0f);
	vertices[2].Position = D3DXVECTOR3( 0.5f, -0.5f, 0.0f);

	vertices[3].Position = D3DXVECTOR3( 0.5f, -0.5f, 0.0f);
	vertices[4].Position = D3DXVECTOR3(-0.5f,  0.5f, 0.0f);
	vertices[5].Position = D3DXVECTOR3( 0.5f,  0.5f, 0.0f);
}

void TestVertex::Ready()
{
	CsResource::CreateRawBuffer(sizeof(Vertex) * 6, vertices, &vertexBuffer);
}

void TestVertex::Destroy()
{
	SAFE_DELETE(shader);
	SAFE_RELEASE(vertexBuffer);
}

void TestVertex::Update()
{
	
}

void TestVertex::PreRender()
{

}

void TestVertex::Render()
{
	UINT stride = sizeof(Vertex);
	UINT offset = 0;

	D3D::GetDC()->IASetVertexBuffers(0, 1, &vertexBuffer, &stride, &offset);
	D3D::GetDC()->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

	shader->Draw(0, 0, 3, 3);
}