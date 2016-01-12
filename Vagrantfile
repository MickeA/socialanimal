# Alter the user settings below to your taste.
# NOTE: Composer install may seem to take forever,
# The install is not broken, be patient.
# This is a function of Composer being a steaming pile of poo, nothing else.

###
# User settings
###
box_name = "socialanimal.se"
box_host = "socialanimal.dev"
box_mem = 3096
box_ip =  "192.168.50.123"

###
vagrant_root = File.dirname(__FILE__)
share_root = "/srv/www/"  + vagrant_root.split('/').last

Vagrant.configure("2")  do |config|
    config.vm.box = "ubuntu/trusty64"

    # Disable totally unnecessary default shared folder
    config.vm.synced_folder '.', '/vagrant', :id => 'vagrant-root', :disabled => true


    # Assign this VM to a host only network IP, allowing you to access it
    # via the IP.
    config.vm.network :private_network, ip: box_ip
    ## Use for windows testing
    # config.vm.network "forwarded_port", guest: 80, host: 8080
    config.vm.hostname = box_host
    config.vm.provider "virtualbox" do |v|
        v.name = box_name
        v.customize ["modifyvm", :id, "--memory", box_mem]
        v.customize ["modifyvm", :id, "--cpus", "1"]
    end

    # Provisioning settings.
    config.vm.provision "ansible" do |ansible|
        ansible.playbook = "provision/site.yml"
        ansible.sudo = true
        # Vhost and PHP settings - change if needed
        ansible.extra_vars = {
          server_hostname: config.vm.hostname,
          drupal_root: share_root + "/web",
          mysql_root_password: "password",
          php_memory_limit: "2048M",
          composer_user: "vagrant",
          drush_version: "8.0.0",
          composer_user_home: "/home/vagrant",
          box_mem: box_mem,
        }
    end

    # The path to the platform
    config.vm.synced_folder vagrant_root, share_root, :nfs => true, :nfs_udp => true

end
