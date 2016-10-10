#ifndef JAVA_PROJECT_H
#define JAVA_PROJECT_H

#include <memory>

#include "settings/JavaProjectSettings.h"
#include "Project.h"

class JavaProject: public Project
{
public:
	JavaProject(
		std::shared_ptr<JavaProjectSettings> projectSettings,
		StorageAccessProxy* storageAccessProxy,
		DialogView* dialogView
	);
	virtual ~JavaProject();

protected:
	virtual std::shared_ptr<ProjectSettings> getProjectSettings();
	virtual const std::shared_ptr<ProjectSettings> getProjectSettings() const;

private:
	JavaProject(const JavaProject&);

	virtual bool prepareIndexing();

	virtual std::shared_ptr<Task> createIndexerTask(
		std::shared_ptr<StorageProvider> storageProvider,
		std::shared_ptr<FileRegister> fileRegister);

	virtual void updateFileManager(FileManager& fileManager);
	
	void fetchRootDirectories();

	std::shared_ptr<JavaProjectSettings> m_projectSettings;
	std::shared_ptr<std::set<FilePath>> m_rootDirectories;

	friend Project;
};

#endif // JAVA_PROJECT_H