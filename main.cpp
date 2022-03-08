#include "NOU/App.h" 
#include "NOU/Input.h" 
#include "NOU/Entity.h" 
#include "NOU/CCamera.h" 
#include "NOU/CMeshRenderer.h" 
#include "NOU/Shader.h" 
#include "NOU/GLTFLoader.h" 

#include <iostream>

//try making a custom 3d texture class?

//all above inclusions are from NOU
//i am using this in order to create an aesthetically pleasing scene with entities, easier
#include "imgui.h" 
using namespace nou;
void LoadDefaultResources();
//make one shader to use
std::unique_ptr<ShaderProgram> shader;

int shaderToggleInfo = 0;//the data to tell the shader what to toggle 
bool isPowerful = false;
// Templated LERP function 
template<typename T>
T Lerp(const T& p0, const T& p1, float t)
{
	return (1.0f - t) * p0 + t * p1;
}
std::vector<Entity*> renderingEntities;
int main() {
	App::Init("CG Assignment 1 - 100782747", 1280, 720);
	App::SetClearColor(glm::vec4(0.611, 0.850, 1, 1.f));
	// Initialize ImGui 
	App::InitImgui();

	// Load in our model/texture resources 
	LoadDefaultResources();


	// Create and set up camera 
	Entity cameraEntity = Entity::Create();
	CCamera& cam = cameraEntity.Add<CCamera>(cameraEntity);
	cam.Perspective(60.0f, (float)1280 / 720, 0.001f, 100.0f);
	//cam.Perspective(100.f, (float) width/height, 0.1f, 100.0f); 
	cameraEntity.transform.m_pos = glm::vec3(-0.7f, -1.2f, -10.7f);
	cameraEntity.transform.m_rotation = glm::angleAxis(glm::radians(0.f), glm::vec3(0.0f, 1.0f, 0.0f));
	//cameraEntity.transform.m_rotation = glm::angleAxis(glm::radians(0.f), glm::vec3(0.0f, 1.0f, 0.0f));


	

/*
	std::unique_ptr<Mesh> backgroundMesh = std::make_unique<Mesh>();

	GLTF::LoadMesh("background.gltf", *backgroundMesh);
	std::unique_ptr<Texture2D> backgroundTexture = std::make_unique<Texture2D>("background.png");
	std::unique_ptr<ShaderProgram> backgroundShader = std::make_unique<ShaderProgram>(*shader);
	std::unique_ptr<Material> backgroundMat = std::make_unique<Material>(*backgroundShader);

	backgroundMat->AddTexture("albedo", *backgroundTexture);

	*/

	std::unique_ptr<Mesh> pacMesh = std::make_unique<Mesh>();

	GLTF::LoadMesh("shape.gltf", *pacMesh);
	std::unique_ptr<Texture2D> pacTexture = std::make_unique<Texture2D>("pac.png");
	std::unique_ptr<ShaderProgram> pacShader = std::make_unique<ShaderProgram>(*shader);
	std::unique_ptr<Material> pacMat = std::make_unique<Material>(*pacShader);

	pacMat->AddTexture("albedo", *pacTexture);
	



	Entity pac = Entity::Create();
	pac.Add<CMeshRenderer>(pac, *pacMesh, *pacMat);
	pac.transform.m_scale = glm::vec3(0.266);
	pac.transform.m_rotation = glm::angleAxis(glm::radians(00.f), glm::vec3(0.0f, 1.0f, 0.0f))
		* glm::angleAxis(glm::radians(90.f), glm::vec3(1.0f, 0.0f, 0.0f))
		* glm::angleAxis(glm::radians(0.f), glm::vec3(0.0f, 0.0f, 1.0f));
	pac.transform.m_pos = glm::vec3(-0.526, -1.599, -14.464);
	//pac.transform.m_pos = glm::vec3(-2.760, -1.599, -12.464);
	renderingEntities.push_back(&pac);
	//chick.transform.RecomputeGlobal();



	std::unique_ptr<Mesh> pelletMesh = std::make_unique<Mesh>();

	GLTF::LoadMesh("shape.gltf", *pelletMesh);
	std::unique_ptr<Texture2D> pelletTexture = std::make_unique<Texture2D>("pellet.png");
	std::unique_ptr<ShaderProgram> pelletShader = std::make_unique<ShaderProgram>(*shader);
	std::unique_ptr<Material> pelletMat = std::make_unique<Material>(*pelletShader);

	pelletMat->AddTexture("albedo", *pelletTexture);


	Entity pellet = Entity::Create();
	pellet.Add<CMeshRenderer>(pellet, *pelletMesh, *pelletMat);
	pellet.transform.m_scale = glm::vec3(0.166);
	pellet.transform.m_rotation = glm::angleAxis(glm::radians(00.f), glm::vec3(0.0f, 1.0f, 0.0f))
		* glm::angleAxis(glm::radians(90.f), glm::vec3(1.0f, 0.0f, 0.0f))
		* glm::angleAxis(glm::radians(0.f), glm::vec3(0.0f, 0.0f, 1.0f));
	pellet.transform.m_pos = glm::vec3(-0.826, -2.309, -14.464);
	//pellet.transform.m_pos = glm::vec3(-2.760, -1.599, -12.464);
	renderingEntities.push_back(&pellet);


	std::unique_ptr<Mesh> ghostMesh = std::make_unique<Mesh>();

	GLTF::LoadMesh("shape.gltf", *ghostMesh);
	std::unique_ptr<Texture2D> ghostTexture = std::make_unique<Texture2D>("ghost.png");
	std::unique_ptr<ShaderProgram> ghostShader = std::make_unique<ShaderProgram>(*shader);
	std::unique_ptr<Material> ghostMat = std::make_unique<Material>(*ghostShader);

	ghostMat->AddTexture("albedo", *ghostTexture);


	Entity ghost = Entity::Create();
	ghost.Add<CMeshRenderer>(ghost, *ghostMesh, *ghostMat);
	ghost.transform.m_scale = glm::vec3(0.266);
	ghost.transform.m_rotation = glm::angleAxis(glm::radians(00.f), glm::vec3(0.0f, 1.0f, 0.0f))
		* glm::angleAxis(glm::radians(90.f), glm::vec3(1.0f, 0.0f, 0.0f))
		* glm::angleAxis(glm::radians(0.f), glm::vec3(0.0f, 0.0f, 1.0f));
	ghost.transform.m_pos = glm::vec3(-0.526, -0.509, -14.464);
	//ghost.transform.m_pos = glm::vec3(-2.760, -1.599, -12.464);
	renderingEntities.push_back(&ghost);

	std::unique_ptr<Mesh> superPelletMesh = std::make_unique<Mesh>();

	GLTF::LoadMesh("shape.gltf", *superPelletMesh);
	std::unique_ptr<Texture2D> superPelletTexture = std::make_unique<Texture2D>("superPellet.png");
	std::unique_ptr<ShaderProgram> superPelletShader = std::make_unique<ShaderProgram>(*shader);
	std::unique_ptr<Material> superPelletMat = std::make_unique<Material>(*superPelletShader);

	superPelletMat->AddTexture("albedo", *superPelletTexture);


	Entity superPellet = Entity::Create();
	superPellet.Add<CMeshRenderer>(superPellet, *superPelletMesh, *superPelletMat);
	superPellet.transform.m_scale = glm::vec3(0.166);
	superPellet.transform.m_rotation = glm::angleAxis(glm::radians(00.f), glm::vec3(0.0f, 1.0f, 0.0f))
		* glm::angleAxis(glm::radians(90.f), glm::vec3(1.0f, 0.0f, 0.0f))
		* glm::angleAxis(glm::radians(0.f), glm::vec3(0.0f, 0.0f, 1.0f));
	superPellet.transform.m_pos = glm::vec3(-0.526, -0.109, -14.464);
	//superPellet.transform.m_pos = glm::vec3(-2.760, -1.599, -12.464);
	renderingEntities.push_back(&superPellet);

	std::unique_ptr<Mesh> winMesh = std::make_unique<Mesh>();

	GLTF::LoadMesh("tile.gltf", *winMesh);
	std::unique_ptr<Texture2D> winTexture = std::make_unique<Texture2D>("win.png");
	std::unique_ptr<ShaderProgram> winShader = std::make_unique<ShaderProgram>(*shader);
	std::unique_ptr<Material> winMat = std::make_unique<Material>(*winShader);

	winMat->AddTexture("albedo", *winTexture);

	std::unique_ptr<Mesh> loseMesh = std::make_unique<Mesh>();
	GLTF::LoadMesh("tile.gltf", *loseMesh);
	std::unique_ptr<Texture2D> loseTexture = std::make_unique<Texture2D>("lose.png");
	std::unique_ptr<ShaderProgram> loseShader = std::make_unique<ShaderProgram>(*shader);
	std::unique_ptr<Material> loseMat = std::make_unique<Material>(*loseShader);

	loseMat->AddTexture("albedo", *loseTexture);


	Entity tile = Entity::Create();
	tile.Add<CMeshRenderer>(tile, *winMesh, *winMat);
	tile.transform.m_scale = glm::vec3(1.3);
	tile.transform.m_rotation = glm::angleAxis(glm::radians(00.f), glm::vec3(0.0f, 1.0f, 0.0f))
		* glm::angleAxis(glm::radians(90.f), glm::vec3(1.0f, 0.0f, 0.0f))
		* glm::angleAxis(glm::radians(0.f), glm::vec3(0.0f, 0.0f, 1.0f));
	tile.transform.m_pos = glm::vec3(-0.526, -0.309, -14.464);
	//tile.transform.m_pos = glm::vec3(-2.760, -1.599, -12.464);
	//renderingEntities.push_back(&tile);
	/*
	Entity background = Entity::Create();
	background.Add<CMeshRenderer>(background, *backgroundMesh, *backgroundMat);
	background.transform.m_scale = glm::vec3(0.469);
	background.transform.m_rotation = glm::angleAxis(glm::radians(0.f), glm::vec3(0.0f, 1.0f, 0.0f))
		* glm::angleAxis(glm::radians(0.f), glm::vec3(1.0f, 0.0f, 0.0f))
		* glm::angleAxis(glm::radians(0.f), glm::vec3(0.0f, 0.0f, 1.0f));
	background.transform.m_pos = glm::vec3(-0.700, -2.239, -12.895);
	renderingEntities.push_back(&background);
	//background.transform.RecomputeGlobal();
	*/

	//glUniform1i(shader->GetUniformLoc("LUT"), 0);
	//glUniform1i(shader->GetUniformLoc("LUT2"), 1);

	App::Tick();
	float scale = 0;

	float t = 0;
	float a = 0, b = 0, c = 0;
	float stren = 0.f;
	int mode = 0;
	int mode2 = 0;
	float speed = 3;
	float daySeconds = 5;
	float currentDaySeconds = 0;
	float tMulti = 1;
	float dayMulti = 1;
	glm::vec3 dayLight = glm::vec3(0.95);
	glm::vec3 nightLight = glm::vec3(0.25);

	glm::vec3 spinVector = glm::vec3(90, 45, 75);
	//shader.get()->GetUniformLoc("LUT");//calls glGetUniformLocation in shader

	while (!App::IsClosing() && (!Input::GetKeyDown(GLFW_KEY_BACKSPACE) && !Input::GetKeyDown(GLFW_KEY_ESCAPE)))
	{
		App::FrameStart();
		float deltaTime = App::GetDeltaTime();
		cameraEntity.Get<CCamera>().Update();
		cameraEntity.transform.RecomputeGlobal();
		t += deltaTime / 5 * tMulti;
		if (t > 1) {
			t = 0;
		}

		currentDaySeconds += deltaTime / daySeconds * dayMulti;
		if (currentDaySeconds > 1 || currentDaySeconds < 0) {
			dayMulti *= -1;
		}
		//ShaderProgram::Current()->SetUniform("LUT", transform.GetNormal());

		//glBindTextureUnit(LUTTexture.get()->GetID(), shader.get()->GetUniformLoc("LUT"));
	
		shader.get()->Bind();
		shader.get()->SetUniform("mode", mode);
		shader.get()->SetUniform("mode2", mode2);
		shader.get()->SetUniform("lightColor", Lerp(dayLight,nightLight,currentDaySeconds));

		//but now how do you link "LUT" to the texture at LUTTexture.get()->getID()?
		for each (Entity * e in renderingEntities) {
		
			e->transform.RecomputeGlobal();
			e->Get<CMeshRenderer>().Draw();
		}

		/*
		App::StartImgui();
		ImGui::SetNextWindowPos(ImVec2(0, 800), ImGuiCond_FirstUseEver);
		ImGui::DragFloat("X", &(a), 0.1f);
		ImGui::DragFloat("Y", &(b), 0.1f);
		ImGui::DragFloat("Z", &(c), 0.1f);
		ImGui::DragFloat("S", &(scale), 0.1f);
		//ImGui::DragInt("M", &(mode), 0.01);
		App::EndImgui();
		//chick.transform.m_pos = Lerp(glm::vec3(1.450, -1.599, -12.464), glm::vec3(-2.760, -1.599, -12.464), t);
		*/
		glm::vec2 vel = glm::vec2(0,0);
		if (Input::GetKey(GLFW_KEY_W)) {
			vel += glm::vec2(0, 1);
		}
		if (Input::GetKey(GLFW_KEY_S)) {
			vel += glm::vec2(0, -1);
		}
		if (Input::GetKey(GLFW_KEY_A)) {
			vel += glm::vec2(-1, 0);
		}
		if (Input::GetKey(GLFW_KEY_D)) {
			vel += glm::vec2(1, 0);
		}

		pac.transform.m_pos.x += vel.x * speed * deltaTime;
		pac.transform.m_pos.y += vel.y * speed * deltaTime;
		
		
		
		//pellet.transform.m_rotation.x += speed * deltaTime;
		//superPellet.transform.m_rotation.x -= speed * deltaTime;
		superPellet.transform.m_rotation = glm::angleAxis(glm::radians(0.f), glm::vec3(0.0f, 1.0f, 0.0f))
			* glm::angleAxis(glm::radians(90.f + Lerp(0,360,t)), glm::vec3(1.0f, 0.0f, 0.0f))
			* glm::angleAxis(glm::radians(0.f), glm::vec3(0.0f, 0.0f, 1.0f));

		ghost.transform.m_pos = Lerp(glm::vec3(1.450, -0.599, -14.464), glm::vec3(-2.760, -0.599, -14.464), t);
		if (glm::distance(pac.transform.m_pos, ghost.transform.m_pos) < 0.5) {
			if (!isPowerful) {
				tile.Remove<CMeshRenderer>();
				tile.Add<CMeshRenderer>(tile, *loseMesh, *loseMat);

				renderingEntities.push_back(&tile);
			}
			else
			{
				renderingEntities.push_back(&tile);
			}
			renderingEntities.erase(std::remove(renderingEntities.begin(), renderingEntities.end(), &ghost), renderingEntities.end());
			renderingEntities.erase(std::remove(renderingEntities.begin(), renderingEntities.end(), &pac), renderingEntities.end());
			renderingEntities.erase(std::remove(renderingEntities.begin(), renderingEntities.end(), &superPellet), renderingEntities.end());
			renderingEntities.erase(std::remove(renderingEntities.begin(), renderingEntities.end(), &pellet), renderingEntities.end());

		}

		if (glm::distance(pac.transform.m_pos, superPellet.transform.m_pos) < 0.25) {
			isPowerful = true;
			renderingEntities.erase(std::remove(renderingEntities.begin(), renderingEntities.end(), &superPellet), renderingEntities.end());

		}

		if (glm::distance(pac.transform.m_pos, pellet.transform.m_pos) < 0.25) {
			//isPowerful = true;
			renderingEntities.erase(std::remove(renderingEntities.begin(), renderingEntities.end(), &pellet), renderingEntities.end());

		}
		
		if (Input::GetKeyDown(GLFW_KEY_1)) {
			mode = 1;
		}
		if (Input::GetKeyDown(GLFW_KEY_2)) {
			mode = 2;
		}
		if (Input::GetKeyDown(GLFW_KEY_3)) {
			mode = 3;
		}
		if (Input::GetKeyDown(GLFW_KEY_4)) {
			mode = 4;
		}
		if (Input::GetKeyDown(GLFW_KEY_0)) {
			mode = 0;
		}
		if (Input::GetKeyDown(GLFW_KEY_5)) {
			if (mode2 == 1) {
				mode2 = 0;
			}
			else
			{
				mode2 = 1;
			}
			
		}
		//std::cout << glm::distance(pac.transform.m_pos, ghost.transform.m_pos) << std::endl;
		App::SwapBuffers();
	}
	App::Cleanup();
	
	return 0;
}

void LoadDefaultResources() {
	// Load in the shaders we will need and activate them 
	// Textured lit shader 
	std::unique_ptr vs_Shader = std::make_unique<Shader>("shaderVS.vert", GL_VERTEX_SHADER);
	//std::unique_ptr fs_texLitShader = std::make_unique<Shader>("shaders/texturedlit.frag", GL_FRAGMENT_SHADER);
	std::unique_ptr fs_Shader = std::make_unique<Shader>("shaderFS.frag", GL_FRAGMENT_SHADER);
	std::vector<Shader*> texLit = { vs_Shader.get(), fs_Shader.get() };
	shader = std::make_unique<ShaderProgram>(texLit);
}
