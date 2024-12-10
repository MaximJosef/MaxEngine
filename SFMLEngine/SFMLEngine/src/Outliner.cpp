#include "Outliner.h"

void Outliner::DrawOutliner()
{
	ImGui::Begin("Outliner");
	for (auto& objectsForRender : object.GetGameObjects())
	{
		const std::string& objectName = objectsForRender->GetObjectName();
		if (objectName.empty()) continue; 

		if (ImGui::Button(objectName.c_str()))
		{
			currentGameObject = objectsForRender;
		}
	}
	ImGui::End();
}
