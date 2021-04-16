#include <stdio.h>
#include <git2.h>


int main(void)
{
	git_libgit2_init();
	// Open git repository
	printf("Open git repository\n");
	git_repository *repo;
	const char * REPO_PATH = "/home/proprietaire/git/learninglibgit2/";
	int error = git_repository_open(&repo,REPO_PATH);

	// Dereference HEAD to a commit
	printf("Dereference HEAD to a commit");
	git_object *head_commit;
	error = git_revparse_single(&head_commit, repo, "HEAD^{commit}");
	git_commit *commit = (git_commit*)head_commit;

	// Print some of the commit's properties
	printf("Print some of the commit's properties\n");
	printf("%s", git_commit_message(commit));
	const git_signature *author = git_commit_author(commit);
	printf("%s <%s>\n",author->name,author->email);
	const git_oid *tree_id = git_commit_tree_id(commit);

	// Cleanup
	printf("Cleanup\n");
	git_commit_free(commit);
	git_repository_free(repo);
}
