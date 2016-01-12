# Socialstyrelsen
Repo for Social Animal

## Installation
```
vagrant up

vagrant ssh

cd /srv/www/socialstyrelsen
composer install

Now we can install the site using our custom profile:
Inside /srv/www/socialstyrelsen/web/sites
drush si socialstyrelsen --account-name=admin --account-pass=admin --site-name="socialstyrelsen" --db-url=mysql://root:password@localhost/drupal -y

```

## Configuration management

After installation you should enable the module site_deploy that will override the system.site uuid and this will let you import all the configuration using a different database.

All the configuration management is in the folder /staging to make it work we have to add this line to settings.php

```
$config_directories['staging'] = '../staging';
```

To import the config we can use:

```
drush config-import staging
```

To export the config we can use:

```
drush config-export staging
```

## Development workflow

```
git checkout master     // in your local machine
git reset --hard
./install     // inside vagrant
git checkout -b new_branch master
```

Make your changes: edit content types, create entities references,...
```
drush config-export staging     // inside /web in my vagrant machine
git add files_related_to_your_changes
git commit -m "new-branch:adding new stuff"
git push -u origin new_branch
```
Create pull request.


## Testing workflow

```
git fetch origin     // copies all branches from remote to local
git branch           // check you have now locally the new branch for testing
git checkout master
./install            // inside the vagrant machine
// Execute cron if you don't see the changes
git checkout branch_for_testing      // before called it new_branch
drush config-import staging    // inside /web in my vagrant machine
drush cr // Or execute cron, just in case
```


## Deploy

No deploy process in place for prod or stage on elastx

## Remove twig cache while developing

Uncomment this in settings.php:
```
if (file_exists(__DIR__ . '/settings.local.php')) {
   include __DIR__ . '/settings.local.php';
}
```

Edit the parameters at service.yml

