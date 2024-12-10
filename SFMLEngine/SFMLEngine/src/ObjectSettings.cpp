#include "ObjectSettings.h"

void ObjectSettings::DrawObjectSettings(GameObject* GameObject)
{
	ImGui::Begin("Object Settings");

	if (GameObject != nullptr)
	{
		ImGui::Text(GameObject->GetObjectName().c_str());

		sf::Vector2f scale = GameObject->GetObjectScale();
		sf::Vector2f positon = GameObject->GetObjectPosition();
		float rotation = GameObject->GetObjectRotation();

		ImGui::SliderFloat("Scale X", &scale.x, 0.1, 100);
		ImGui::SliderFloat("Scale Y", &scale.y, 0.1, 100);
		GameObject->SetObjectScale(scale);

		ImGui::SliderFloat("Position X", &positon.x, 0, Display::WIDTH);
		ImGui::SliderFloat("Position Y", &positon.y, 0, Display::HEIGHT);
		GameObject->SetObjectPosition(positon);

		ImGui::SliderFloat("Rotation", &rotation, 0, 360);
		GameObject->SetObjectRotation(rotation);

		if (ImGui::Button("Change Texture")) 
		{
			IGFD::FileDialogConfig config;
			config.path = ".";
			ImGuiFileDialog::Instance()->OpenDialog("ChooseFileDlgKey", "Choose File", ".jpg,.jpeg,.png", config);
		}
		if (ImGuiFileDialog::Instance()->Display("ChooseFileDlgKey")) 
		{
			if (ImGuiFileDialog::Instance()->IsOk()) 
			{ 
				std::string filePathName = ImGuiFileDialog::Instance()->GetFilePathName();
				std::string filePath = ImGuiFileDialog::Instance()->GetCurrentPath();
				GameObject->SetObjectTexture(AssetManager::GetTexture(filePathName));
			}

			ImGuiFileDialog::Instance()->Close();
		}
	}
	ImGui::End();
}
