#include <git2.h>
#include <iostream>

int main(int argc, char *argv[])
{
	git_libgit2_init(); // The first thing to do is to call git_libgit2_init
       			    // to initialise libgit2 and its resources.

	const char * REPO_PATH = "/home/proprietaire/git/learninglibgit2/";

	git_repository * repo = nullptr;
	git_repository_open(&repo, REPO_PATH);
	// You open a repository using git_repository_open, 
	// which creates an object you can use to interact with 
	// a repository in your code.	

	git_revwalk * walker = nullptr;
	git_revwalk_new(&walker,repo);
	// The next step is to create a revision walker,
	// the object which iterates through a git repository.
	// This is done by the git_revwalk_new function.
	
	git_revwalk_sorting(walker, GIT_SORT_NONE);
	// + GIT_SORT_NONE – default reverse chronological order 
	// (starts from most recent) of commits as in git
        // + GIT_SORT_TOPOLOGICAL – topological order,
	// shows no parent before all of its children are shown
        // + GIT_SORT_TIME – commit timestamp order
        // + GIT_SORT_REVERSE – commits in reverse order

	git_revwalk_push_head(walker);
	// Calling git_revwalk_push_head sets the root to the repository’s HEAD.
	
	git_oid oid;

	// After the setup stage we are ready to start the traversal.
	// This is done by the function git_revwalk_next 
	// which gets the ID of the next commit to visit.
	while(!git_revwalk_next(&oid, walker))
	{
		git_commit * commit = nullptr;
		git_commit_lookup(&commit, repo, &oid);
		// Once we have an ID we can retrieve a git_commit object 
		// calling git_commit_lookup. We will use this object 
		// to retrieve information about the commit.

		std::cout << git_oid_tostr_s(&oid)
			  << " "
			  << git_commit_summary(commit)
			  << std::endl; 
		// This is where we get the info we need from the ID 
		// and the commit.
		// We can use git_oid_tostr_s to get the hash of the commit
		// from the ID and git_commit_summary to get the short summary
		// of the commit.
	      
		git_commit_free(commit);
	}

	git_revwalk_free(walker);
	git_repository_free(repo);

	git_libgit2_shutdown();

	return 0;

}
